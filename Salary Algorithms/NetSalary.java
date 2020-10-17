import java.util.Scanner;
class NetSalary{
	public static void main(String[] args){
		//Declare all variable that needed
		String category;
		int salary;
		double tax=0;
		int netSalary;
		//Make scanner for input from keyboard
		Scanner inputZaed = new Scanner(System.in);
		System.out.println("Input your category:");
		category = inputZaed.nextLine();
		System.out.println("Input your salary:");
		salary = inputZaed.nextInt();
		//Make if else to different the salary of Worker and businessman
		if (category.equalsIgnoreCase("Worker")) {
			//specify salary every job and add tax 
			if (salary <= 2000000){
				tax = 0.1;
			}
			else if (salary <= 3000000){
				tax = 0.15;
			}
			else {
				tax = 0.2;
			}
			netSalary = (int) (salary - (salary * tax));
			System.out.println("Gaji bersih yang Anda terima: "+netSalary);
		}
		else if(category.equalsIgnoreCase("businessman")){
			//specify salary every job and add tax 
			if (salary <= 2500000){
				tax = 0.15;
			}
			else if(salary <= 3500000){
				tax = 0.2;
			}
			netSalary = (int) (salary - (salary * tax));
			System.out.println("Your received salary : "+netSalary);
		}
		else{
		//if the input not businessman or worker return to else
			System.out.println("Invalid category input");
		}
	}
}