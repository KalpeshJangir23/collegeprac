#include <iostream>
#include <stack>
 
using namespace std;
 
int set[] = {10, 7, 5, 18, 12, 20, 15};
int numberOfElements = 7, sum = 30;
 
class SubSet{
public:
  stack<int> solutionSet;
  bool hasSolution;
  
  void solve(int s, int idx){
      
    //return if s exceed sum
    if(s>sum)
        return;
    //check if stack has the right subsets of numbers
    if(s==sum){
        hasSolution = true;
        //display stack contents
        displaySolutionSet();
        return;
    }
    for(int i=idx; i<numberOfElements; i++){
        //Adding element to the stack
        solutionSet.push(set[i]);
        solve(s+set[i],i+1);
        solutionSet.pop();
    }
  }
  //Function to display stack content
  void displaySolutionSet(){
        stack<int> temp;
      
        while (!solutionSet.empty()) 
        { 
            cout <<  solutionSet.top() << " "; 
            temp.push(solutionSet.top()); 
            solutionSet.pop();
        } 
        cout << '\n';
        while (!temp.empty()) 
        { 
            solutionSet.push(temp.top()); 
            temp.pop();
        } 
    }
};
 
int main()
{
    SubSet ss;
    ss.solve(0,0);
	    
	if(ss.hasSolution == false)
	    cout << "No Solution";
 
    return 0;
}