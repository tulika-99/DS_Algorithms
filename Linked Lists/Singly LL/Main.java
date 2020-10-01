class Main {
    public static void main(String[] args) {
      LinkedList LL = new LinkedList();
  
      LL.InsertFirst(5);
      LL.InsertFirst(6);
      LL.InsertFirst(7);
  
      LL.InsertLast(60);
  
      int a = LL.nodeCount();
  
      LL.display();
  
      System.out.println(LL.exists(7) + " "+ a);
  
  
    }
  }