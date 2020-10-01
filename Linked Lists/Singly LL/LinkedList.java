public class LinkedList {
  private Node head;

  public LinkedList() {
      this.head = null;
  }

  /**
   * Create a  linked list with an initial node
   * 
   */
  public LinkedList(int data) {
      this.head = new Node(data);
  }

  /**
   * Add a new Node at head
   * 
   */
  public void InsertFirst(int data) {
      Node n = new Node(data);
      if (this.head == null) {
          this.head = n;
      } else {
          n.setNextPointer(head);
          head = n;
      }
  }

  /**
   * Adds a new node in order, starting from the left
   * 
   */
  public void InsertOrder(int data) {
      if (head == null) { // LL is empty
          InsertFirst(data);
          return;
      } else if (!head.hasItem()) { // ll has 1 item
          if (data < head.getData())
              InsertFirst(data);
          else
              InsertLast(data);
      } else {
          Node newNode = new Node(data);
          Node currentNode = head;
          Node nextNode = currentNode.getNextPointer();
          while (currentNode.hasItem() && currentNode.getNextPointer().getData() < data) {
              currentNode = nextNode;
              nextNode = currentNode.getNextPointer();
          }
          newNode.setNextPointer(currentNode.getNextPointer());
          currentNode.setNextPointer(newNode);
      }

  }

  /**
   * Add a new Node at tail
   * 
   */
  public void InsertLast(int data) {
      Node thisNode = head;
      Node newNode = new Node(data);
      if (thisNode == null) { // LL is currently empty
          head = newNode;
          return;
      }
      while (thisNode.hasItem()) {
          thisNode = thisNode.getNextPointer();
      }
      thisNode.setNextPointer(newNode);
  }

  /**
   * Display the linked list
   */
  public void display() {
      System.out.print("[");
      display(this.head);
  }

  public void display(Node node) {
      if (node != null) {
          System.out.print(node.getData() + " > ");
          display(node.getNextPointer());
          return;
      }
      System.out.println("∅]");
  }

  /**
   * Returns true if a node which contains data
   * 
   * @return boolean exists
   */
  public boolean exists(int data) {
      Node node = head;
      while (node != null && node.getData() != data) {
          node = node.getNextPointer();
      }
      return node != null && node.getData() == data;
  }

  /**
   * Returns whether the head is null
   * 
   * @return
   */
  public boolean isEmpty() {
      return head == null;
  }

  /**
   * Get the node pointed by head
   * 
   * @return
   */
  public Node getHead() {
      return head;
  }

  public void setHead(Node node) {
      this.head = node;
  }

  /**
   * Get tail node
   */
  public Node getTail() {
      Node node = head;
      while (node.hasItem()) {
          node = node.getNextPointer();
      }
      return node;
  }

  /**
   * Delete the first Node
   */
  public void deleteFirst() {
      if (head != null) {
          Node prevHead = head;
          head = prevHead.getNextPointer();
          prevHead = null;
      }
  }

  public void deleteLast(){
    if (head == null){
         System.out.print("already empty");
    }
    else {
      Node currentNode = head;
      Node nextNode = currentNode.getNextPointer();
      while (nextNode.hasItem()) {
          currentNode = nextNode;
          nextNode = currentNode.getNextPointer();
      }
      currentNode.setNextPointer(null);
    }
    
}

  /** Counts the number of nodes in the Linked list */
  public int nodeCount() {
      int count = 0;
      Node n = head;
      if (n != null) {
          while (n.hasItem()) {
              count++;
              n = n.getNextPointer();
          }
          count++;
      }
      return count;
  }

  /**
   * Appends a second linked list at the end of the current one
   * 
   * @param sll
   */
  public void merge(LinkedList sll) {
      Node tail = getTail();
      tail.setNextPointer(sll.getHead());
  }

  // public void insertionSort() {
  // if (!isEmpty() || !head.hasItem()) { // has more than 2 items

  // }
  // }

  /**
   * Swaps 2 nodes given the node and their previous node
   * 
   * @param node1prev
   * @param node1
   * @param node2
   * @param node2prev
   */
  // public void swap(Node node1prev, Node node1, Node node2prev, Node node2) {
  //     Node t1 = node1;
  //     Node t2 = node2.getNextPointer();
  //     node1prev.setNextPointer(node2);
  //     node2.setNextPointer(node1.getNextPointer());
  //     node2prev.setNextPointer(t1);
  //     node1.setNextPointer(t2);
  // }
}