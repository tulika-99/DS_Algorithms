use std::cmp::{min, Ordering};
use std::fmt;

#[derive(Clone, Copy, PartialEq, Eq)]
enum Distance {
    Reachable(i32),
    Unreachable,
}

impl PartialOrd for Distance {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(match (self, other) {
            (Distance::Reachable(self_dist), Distance::Reachable(other_dist)) => self_dist.cmp(other_dist),
            (Distance::Reachable(_), Distance::Unreachable) => Ordering::Less,
            (Distance::Unreachable, Distance::Reachable(_)) => Ordering::Greater,
            (Distance::Unreachable, Distance::Unreachable) => Ordering::Equal,
        })
    }
}

// Needed to be able to compare with <, > or ==
impl Ord for Distance {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap() // It's empty
    }
}


impl std::ops::Add for Distance {
    type Output = Self;

    fn add(self, other: Self) -> Self {
        match (self, other) {
            (Distance::Reachable(self_dist), Distance::Reachable(other_dist)) => Distance::Reachable(self_dist + other_dist),
            // At least one is unreachable
            _ => Distance::Unreachable,
        }
    }
}

pub type Vertex = usize;

// Matrix to store the distance/weight of shortest known path between to vertices
struct DistanceMatrix {
    distances: Vec<Vec<Distance>>,
}

impl DistanceMatrix {
    pub fn new(num_vertices: usize) -> Self {
        let mut distances = vec![vec![Distance::Unreachable; num_vertices]; num_vertices];

        for i in 0..num_vertices {
            // Every vertex can always reach itself with distance 0
            distances[i][i] = Distance::Reachable(0);
        }

        Self { distances }
    }

    pub fn get_distance(&self, from: Vertex, to: Vertex) -> Distance {
        self.distances[from][to]
    }

    pub fn set_distance(&mut self, from: Vertex, to: Vertex, distance: Distance) {
        self.distances[from][to] = distance;
    }
}

fn shortest_distance(distances: &DistanceMatrix, from: Vertex, over: Vertex, to: Vertex) -> Distance {
    // Check if the distance by going over 'over' is shorter than the current shortest known path
    min(
        distances.get_distance(from, to),
        distances.get_distance(from, over) + distances.get_distance(over, to)
    )
}

fn main() {
    let vertices: Vec<Vertex> = (0..6).collect();

    let mut distance_matrix = DistanceMatrix::new(vertices.len());

    distance_matrix.set_distance(0, 1, Distance::Reachable(2));
    distance_matrix.set_distance(0, 3, Distance::Reachable(5));

    distance_matrix.set_distance(1, 2, Distance::Reachable(4));

    distance_matrix.set_distance(2, 3, Distance::Reachable(1));
    distance_matrix.set_distance(2, 5, Distance::Reachable(7));

    distance_matrix.set_distance(3, 0, Distance::Reachable(-3));
    distance_matrix.set_distance(3, 1, Distance::Reachable(4));
    distance_matrix.set_distance(3, 2, Distance::Reachable(6));
    distance_matrix.set_distance(3, 4, Distance::Reachable(5));

    distance_matrix.set_distance(4, 2, Distance::Reachable(8));
    distance_matrix.set_distance(4, 5, Distance::Reachable(-1));
    println!("Initial Matrix: {}", &distance_matrix);

    for over in &vertices {
        let mut next_matrix = DistanceMatrix::new(vertices.len());


        for from in &vertices {
            for to in &vertices {
                next_matrix.set_distance(*from, *to, shortest_distance(&distance_matrix, *from, *over, *to));
            }
        }

        distance_matrix = next_matrix;
        println!("After iteration {}: {}", over, &distance_matrix);
    }
}


// ----------------
// Formatting implementations


impl fmt::Display for Distance {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Distance::Reachable(distance) => write!(f, "{: >2}", distance),
            Distance::Unreachable => write!(f, " ∞")
        }
    }
}


impl fmt::Display for DistanceMatrix {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if self.distances.len() == 0 {
            write!(f, "[]")
        } else {
            write!(f, "[\n")?;
            for row in &self.distances {
                write!(f, "    [")?;
                for distance in row {
                    write!(f, "{},", distance)?;
                }
                write!(f, "],\n")?;
            }
            write!(f, "]")
        }
    }
}
