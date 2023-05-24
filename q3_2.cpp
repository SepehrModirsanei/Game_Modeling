#include <iostream>
#include <vector>

using namespace std;

class Situation {
public:
    string Island1;
    string Island2;
    string boat;
    
    void move(vector <char> passengers, const string from, const string to,int count) {
        
        string Action;
        string source = Island2;
        string destination = Island1;

        if (to == "Island1") {
            Action="Left";
            source = Island2;
            destination = Island1;

            for (int j=0; j<passengers.size(); j++){
                for (int i=source.size()-1; i>=0; i--){
                    if (source[i]==passengers[j]){
                        destination.push_back(passengers[j]);
                        source.erase(source.begin() + i);
                        break;
                    }
                }
            }

            cout <<"Action:" << Action << endl;
            cout <<"State" << count << ": ";
            count++;
            sort(destination.begin(),destination.end());
            sort(destination.begin(),destination.end());
            cout <<"[";
            for (int i=0; i< destination.size()-1; i++){
                cout <<"'"<<destination[i]<<",";
            }
            cout <<"'"<<destination[destination.size()-1]<<"'";
            cout << "][";
            for (int j=0; j< source.size()-1; j++){
                cout <<"'"<<source[j]<<"'"<<",";
            }
            if(source.size() != 0)
                cout <<"'"<< source[source.size()-1]<<"'";
            cout << "]" << endl;

            Island2 = source;
            Island1 = destination;

                
        }

           
        if (to =="Island2") {
            
            Action="Right";
            destination = Island2;
            source = Island1;

            for (int j=0; j<passengers.size(); j++){
                for (int i=source.size()-1; i>=0; i--){
                    if (source[i]==passengers[j]){
                        destination.push_back(passengers[j]);
                        source.erase(source.begin() + i);
                        break;
                    }
                }
            }
            cout <<"Action:" << Action << endl;
            cout <<"State"<<count<<": ";
            count++;
            sort(destination.begin(),destination.end());
            sort(destination.begin(),destination.end());
            cout <<"[";
            if(source.size() != 0){
                for (int i=0; i < source.size()-1; i++){
                    cout << "'"<<source[i]<< "'"<<",";
                }
                cout <<"'"<< source[source.size()-1]<<"'";
            }
            cout << "][";
            for (int j=0; j< destination.size()-1; j++){
                cout << "'"<<destination[j]<<"'"<<",";
            }
            cout <<"'"<<destination[destination.size()-1]<<"'";
            cout << "]"<< endl;

            Island1 = source;
            Island2 = destination;
        }
    }
};


class Solution : public Situation {
public:
    void solve() {
        vector <char> ss;
        ss.push_back('S');
        ss.push_back('S');
        move(ss, "Island1", "Island2",2);
        ss.clear();
        ss.push_back('S');
        move(ss, "Island2", "Island1",3);
        ss.clear();
        ss.push_back('L');
        move(ss, "Island1", "Island2",4);
        ss.clear();
        ss.push_back('S');
        move(ss, "Island2", "Island1",5);
        ss.clear();
        ss.push_back('S');
        ss.push_back('S');
        move(ss, "Island1", "Island2",6);
        ss.clear();
        ss.push_back('S');
        move(ss, "Island2", "Island1",7);
        ss.clear();
        ss.push_back('L');
        move(ss, "Island1", "Island2",8);
        ss.clear();
        ss.push_back('S');
        move(ss, "Island2", "Island1",9);
        ss.clear();
        ss.push_back('S');
        ss.push_back('S');
        move(ss, "Island1", "Island2",10);
        
    }
    void PrintSolution(){
        cout << "Solution: 9\n";
        cout <<   "State1: ['L', 'L', 'S', 's'][]\n"             ;
        cout <<   "Action: Right\n"             ;
        cout <<    "State2: ['L', 'L']['S', 'S']\n"            ;

        cout <<  "Action: Left\n"              ;
        cout <<     "State3: ['L', 'L', 'S']['S']\n"           ;
        cout <<    "Action: Right\n"            ;
        cout <<    "State4: ['L', 'S']['L', 'S']\n"            ;
        cout <<   "Action: Left\n"             ;
        cout <<  "State5: ['L', 'S', 'S']['L']\n"               ;
        cout <<     "Action: Right\n"           ;
        cout <<      "State6: ['L']['L', 'S', 'S']\n"          ;
        cout <<         "Action: Left\n"       ;
        cout <<    "State7: ['L', 'S']['L', 'S']\n"            ;
        cout <<   "Action: Right\n"             ;
        cout <<    "State8: ['S']['L', 'L', 'S']\n"            ;
        cout <<    "Action: Left\n"            ;
        cout <<   "State9: ['Ss', 'S']['L', 'L']\n"             ;
        cout << "Action: Right\n";
        cout << "State10: []['L', 'L', 'S', 'S']\n";

    };
};



int main() {
    Solution solution;
    solution.Island1.push_back('L');
    solution.Island1.push_back('L');
    solution.Island1.push_back('S');
    solution.Island1.push_back('S');
    cout << "Solution: 9\n";
    cout <<   "State1: ['L', 'L', 'S', 'S'][]" << endl ;
    
    solution.boat = "Island1";
    solution.Island2 = "";

    solution.solve();
    //solution.PrintSolution();


    return 0;
}
