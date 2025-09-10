//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Employee
{
	private:
		int Emp_id;
		int age;
		string name;
	public:
		Employee(int Emp_id,int age,const string& name):Emp_id(Emp_id),age(age),name(name) {}
		void display() const{
			cout <<"Id is : "<<Emp_id<<"\nAge is :"<<age<<"\nName is :"<<name<<endl;
		}
		int getEmp_id() const 
		{ 
		return Emp_id;
		}
		string get_Name() const{
			return name;
		}
		void set_Age(int N_Age){age = N_Age; }
		void set_Name(const string& N_name){name = N_name; }
};
class EmpManager{
	protected:
		vector<Employee> Employe;
	public:
		void addEmp(const Employee& emp){
			Employe.push_back(emp);
		}
		void dispAll() const{
			for(const auto& e : Employe){ e.display();
			}
		}
		void search_id(int id) const{
			for(const auto& e:Employe)
			{
				if(e.getEmp_id()==id){
					cout << "Found...\n";
					e.display();
					return;
				}
			}
		}
		void search_name(char val) const{
			for(const auto& na:Employe)
			{
				string nam = na.get_Name();
				if(nam[0]==val){
					cout << "String Found...\n";
					na.display();
				}
			}
		}
		void update(int id,int nage,string nname){
			for(auto& e:Employe){
				if(e.getEmp_id()==id){
					e.set_Age(nage);
					e.set_Name(nname);
					return;
				}
			}
		}
		void deleteEmp(int id){
			for(int i=0;i<Employe.size();i++){
				if(Employe[i].getEmp_id()==id){
					Employe.erase(Employe.begin()+i);
					return;
				}
			}
		}
		void sort_id(){
			sort(Employe.begin(),Employe.end(), [](Employee a,Employee b){return a.getEmp_id() < b.getEmp_id();});
		}
		void sort_name(){
			sort(Employe.begin(),Employe.end(), [](Employee a,Employee b){return a.get_Name() < b.get_Name();});
		}
};
int main()
{
	EmpManager mp;
	mp.addEmp(Employee(8,18,"Thanviya"));
	mp.addEmp(Employee(1,56,"Nithish"));
	mp.addEmp(Employee(3,18,"Anu"));
	mp.addEmp(Employee(2,50,"Harini"));
	mp.addEmp(Employee(4,68,"Siva"));
	mp.addEmp(Employee(5,27,"Kumar"));
	mp.addEmp(Employee(7,20,"Dhakshana"));
	mp.addEmp(Employee(9,41,"Sudhar"));
	mp.addEmp(Employee(6,28,"Agila"));
	mp.addEmp(Employee(10,36,"Gowtham"));
	mp.sort_id();
    mp.dispAll();
    mp.search_id(7);
	mp.search_name('A');
	mp.update(1,30,"NK");
	mp.deleteEmp(3);
	mp.dispAll();
	return 0;
}
	
	
