// Source : https://leetcode.com/problems/evaluate-division/


/********************************************************************************** 
* 
* Problem : Equations are given in the format A / B = k, where A and B are variables represented as strings,
            and k is a real number (floating point number).
            Given some queries, return the answers. If the answer does not exist, return -1.0.
* 
  Input: equations = [ ["a", "b"] ],
         values = [2.0, 3.0],
         queries = [ ["a", "c"]
* 
Example :::
* Input : [ ["a","b"],["b","c"] ]
          [2.0,3.0]
          [ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]
* Answer : [6.00000,3.00000,-1.00000,1.00000,-1.00000]
**********************************************************************************/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
       
       string key,value;
       //Storing equations in Directed Map {u,{v,weight} }
       map< string,list< pair<string,double> > > Alist;
       
       //Initialize the map
       for(int i=0;i<equations.size();i++)
       {
           key=equations[i].first;
           value=equations[i].second;
           Alist[key].push_back({value,values[i]}) ; //push_back the pair<string b,value(a/b)>
           Alist[value].push_back({key,1/values[i]}) ; //push_back the pair<string b,value(b/a)>
       }
       
       //main logic :: DFS modified 
      
       stack<string> stk;
       map<string,bool> visited; // map becoz here key is string --->can use vector if key was num 1::n 
       map<string,double> dist;
       vector<double> ans;
       
       string source,target,u,v;
       int exist=0;
       
       for(auto &i:queries)  //traverse the queries
       {
           source=i.first;
           target=i.second;
           visited[source]=true;
           stk.push(source);
           dist[source]=1;
           while(!stk.empty())
           {
               u=stk.top();  //vertex u
               stk.pop();
               if(u==target)
               {
                   if(Alist.find(u)!=Alist.end())exist=1; //found :: element is contained in map !
                        else exist=0;
                   break;
               }
               
               
               for(auto &j:Alist[u])
               {
                    v=j.first;  //vertex v
                    if(visited[v]==false)
                    {
                        visited[u]=true;// not strictly DFS.. can visit 1 level down
                        dist[v]=dist[u]*j.second;
                        stk.push(v);
                    }
               }
               
            }
            if(exist==1)ans.push_back(dist[target]);//<<" ";
            else ans.push_back(-1);//<<" ";
           
           //clearing(for nxt iteration) DATA STRUCTURES used ===>> maps , stack and varible used .
           dist.clear();
           visited.clear();
           while(!stk.empty())stk.pop(); //no direct method for clearing stack !
           exist=0;
       }
       return ans;
      }
};
