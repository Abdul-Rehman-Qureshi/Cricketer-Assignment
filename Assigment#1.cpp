#include <iostream>
using namespace std;

class cricketer {
protected:
	string name;
	int shirt_no;
	string dob;
	int odi_rating;
	int test_rating;
	int t20_rating;
	int startyear;

public:
	cricketer() :name("\0"),shirt_no(0),dob("\0"),odi_rating(0),test_rating(0),t20_rating(0),startyear(0) {
		cout << "\ndefault constructor of criketer is called :)" << endl;

 }
	cricketer(string n, int shno ,string d, int odi, int tstRtng, int t20Rtng, int strtYr) {
		name= n;
		dob = d;
		shirt_no = shno;
		odi=odi_rating;
		test_rating = tstRtng;
		t20_rating = t20Rtng;
		startyear = strtYr;
		cout << "\nparameterized constructor of criketer is called" << endl;

	}
	
	int calculateage(int pd, int pm, int py, int bd, int bm, int by)
	
	{  
		cout << " Enter the present date in the format dd mm yyyy : ";
		cin >> pd >> pm >> py;
		cout << " Enter the birth date in the format dd mm yyyy : ";
		cin >> bd >> bm >> by;

		int d, m, y;
		int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		y = py - by;
		if (pm < bm)
		{
			y--;
			m = 12 - (bm - pm);
		}
		else
		{
			m = pm - bm;
		}
		if (pd < bd)
		{
			m--;
			d = md[pm - 1] - (bd - pd);
		}
		else
		{
			d = pd - bd;
		}
		cout << "your age is : \n";
		cout << y << " years " << m << " months " << d << " days. "<<endl;

	}
	
	 int calculateexperience(int pd,int pm,int py, int bd, int bm, int by ) {

		cout << " Enter the present year : ";
		cin >>  py;
		cout << " Enter the joinning year : ";
		cin >>  by;
		int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int y;
		y = py - by;
		if (pm < bm)
		{
			y--;	
		}

		cout << "your total experience : \n";
		cout << y << " years " << endl ;

	}
	
	void changeODIRating(int z){
		 odi_rating=z;
		cout<<"Entered Odi Rating: " << odi_rating<<endl;
	}
	void changeTestRating(int x){
		test_rating=x;
		cout<< "Enterd Test Rating is: " <<test_rating<< endl;
	
	}
	void changeT20Rating(int y){
		t20_rating=y;
		cout << "Enterd T20 Rating is: " << t20_rating << endl;	
	}
	~cricketer(){
		cout<<"\nDestructor of cricketer is here :( " <<endl;
	}
};
	class Bowler:public cricketer {
	private:
		string type;
		int total_wickets;
		int match_played;
		
		public:
			Bowler():type("\0"),total_wickets(0),match_played(0) {
				cout<< "\nDefault constructor Bowler." << endl;
				
			}
			Bowler(string a1,int a2,int a3,string n, int shno ,string d, int odi, 
			 int tstRtng, int t20Rtng, int strtYr)
			  	{
			        type=a1;
					total_wickets=a2;
					match_played=a3;
					cout<<"\nParameterized constructor of Bowler."<< endl;
				}
			void calculbowlavg(){
				int avg,numofwick,numofmatch;
				cout<<"Enter Number of Wickets of Bowler" <<endl;
				cin>>numofwick;
				cout<<"Enter Number of Macthes played of Bowler" << endl;
				cin>>numofmatch;
				avg=numofwick/numofmatch;
				cout<<"bowler average is: " <<avg <<endl;
			}
			
			void updatebowMacthes(){
				int playmatch;
				cout<<"Enter Played Macthes of Bowler" <<endl;
				cin>>playmatch;
			match_played=playmatch;
			cout << "Bowler Played Macthes is:" << match_played <<endl;
				
			}
			void updatebowWickets(){
				int ttlw;
				cout<<"Enter total wickets of Bowler" <<endl;
				cin>>ttlw;
				total_wickets=ttlw;
				cout<<"Toal wickets of Bowler " << total_wickets << endl;
			}
			 ~Bowler(){
			 	cout<< "\nDestrucotor of Bowler:" << endl;
			 }
			
			};
	class Batsman:public cricketer {
		private:
		string type1;
		int total_runs;
		int match_played1;
		int best_score;

		public:
			Batsman():type1("\0"),total_runs(0),match_played1(0), best_score(0){
				cout<< "\nDefault constructor Batsman. making all valus to null " << endl;
			}
			Batsman(string z1,int z2,int z3,int z4,string n, int shno
			        ,string d, int odi, int tstRtng, int t20Rtng, int strtYr){
			        	type1=z1;
			        	match_played1=z2;
			        	best_score=z3;
			        cout<<"\nParameterized constructor of Batsman;" << endl;
			}
		int calculateBatAverage(){
			int avg1,numr,numwp;
			cout<<"Enter Number of Runs Batsman" <<endl;
			cin>>numr;
			cout<<"Number of Matches Played Batsman" << endl;
			cin>>numwp;
			avg1=numr/numwp;
			cout<<"Batsman Average is " << avg1 << endl;
		}  
		
		void updatebatMatches(){
			int mat1;
			cout<<"Enter Matches of Batsman: " <<endl;
			cin>>mat1;
			match_played1=mat1;
			cout<<"Enterd Macthes is of Batsman" <<match_played1 << endl;
		}  
		
		void updatebatRuns() {
			int runs1;
			cout<<"Enter runs for batsman " <<endl;
			cin>>runs1;
			total_runs=runs1;
			cout<<"Enterd  run of batsman is : " << total_runs << endl;
			
		}
		~ Batsman() {
			cout<< "\n~Batsman Destructor;" << endl;
		}
	};
	
	class AllRounder:public Bowler,public Batsman{
			AllRounder()
	{
		cout<<"\nALL rounder constructor is here" << endl;
	}
	~AllRounder()
	{
		cout<<"\nAll rounder Destrucotr is here;" << endl;
	}
	};		
			
	
int main(){
	int pd, pm, py, bd, bm, by;
	
	cricketer c1;
	c1.calculateexperience(pd, pm, py, bd, bm, by);
	c1.calculateage(pd, pm, py, bd, bm, by);
	c1.changeT20Rating(10);
	
	Bowler bow1;
	bow1.calculbowlavg();
	bow1.updatebowMacthes();

	Batsman bt3;
	bt3.updatebatRuns();
	bt3.calculateBatAverage();
	
}
