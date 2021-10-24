const intervalSchedulingMaximization = (schedules) => {
    schedules.sort((s1, s2) => s1.f > s2.f ? 1 : -1);
    let count = 1;
    let ind = 0;
    for (let i = 1; i < schedules.length; i++) {
        if (!overlap(schedules[ind], schedules[i])) {
            ind = i;
            count++;
        }
    }
    return count;
}

const overlap = (s1, s2) => (s2.s >= s1.s && s2.s < s1.f) ||
    (s2.f >= s1.s && s2.f < s1.f) ||
    (s2.s <= s1.s && s2.f >= s1.f)