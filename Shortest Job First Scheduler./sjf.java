import java.util.*;
class Proc{

	String name;
	int at;
	int bt;

}

class sjf{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the total number of processes: ");
		int n = sc.nextInt();
		ArrayList<Proc> process = new ArrayList<Proc>();

		//Assuming all the processes will arive in non-decreasing order of their arrival time. If not, sort it accordingly.
		for(int i = 0; i < n; i++){
			
			System.out.print("\nEnter the process name: ");
			String name = sc.next();

			System.out.print("\nEnter the process arrival time: ");
			int at = sc.nextInt();

			System.out.print("\nEnter the process burst time: ");
			int bt = sc.nextInt();

			Proc temp = new Proc();
			temp.name = name;
			temp.at = at;
			temp.bt = bt;

			process.add(temp);
		}

		// Heap will be implemented using an ArrayList for dynamic arrival of processes.
		ArrayList<Proc> p = new ArrayList<Proc>();
		
		p.add(process.remove(0));
		
		int totalExecTime = 0;

		while(process.size()>0){

			if(p.isEmpty()==false){
				Proc temp = p.remove(0);
				totalExecTime += temp.bt;
				System.out.print(temp.name + " ");
			}
			else
				totalExecTime += 1;

			while(process.size()>0 && totalExecTime>=process.get(0).at){
				p.add(process.remove(0));
			}
			// Heapify here.
			int n1 = p.size() - 1;
			int i = n1;

			if(i>=0){
				Proc temp1 = new Proc();
				temp1 = p.get(n1);
				while(i>0 && p.get((i / 2)).bt > temp1.bt){
					p.set(i, p.get(i / 2));
					i = i / 2;
				}
				p.set(i, temp1);	
			}
		}

		// To print the remaining process.
		for(int j = 0; j < p.size(); j++){
			System.out.print(p.get(j).name + " ");
		}
	}
}