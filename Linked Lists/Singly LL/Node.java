/**
 * Node
 */
public class Node {
  private Node previousPointer;
  private Node nextPointer;
  private int data;

  // public Node() {
  //     this.previousPointer = null;
  //     this.nextPointer = null;
  //     this.data = null;
  // }

  public Node(int data) {
      this.previousPointer = null;
      this.nextPointer = null;
      this.data = data;
  }

  public Node getPreviousPointer() {
      return this.previousPointer;
  }

  public void setPreviousPointer(Node previousPointer) {
      this.previousPointer = previousPointer;
  }

  public Node getNextPointer() {
      return this.nextPointer;
  }

  public void setNextPointer(Node nextPointer) {
      this.nextPointer = nextPointer;
  }

  public boolean hasItem() {
      return nextPointer != null;
  }

  public int getData() {
      return this.data;
  }

  public void setData(int data) {
      this.data = data;
  }

}