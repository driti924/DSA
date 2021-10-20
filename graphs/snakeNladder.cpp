#include <bits/stdc++.h>
using namespace std;

int main()
{
    int snakesN, ladderN;
    cin>>ladderN;

    map<int, int> snakes;
    map<int, int> ladders;
    
    for(int i=0;i<ladderN;i++){
        int u, v;
        cin>>u>>v;
        ladders[u]=v;
    }
    cin>>snakesN;

    for(int i=0;i<snakesN;i++){
        int u, v;
        cin>>u>>v;
        snakes[u]=v;
    }
    
    int moves=0;
    vector<bool> vis(101, 0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    bool found=0;//if we reach 100
    while(!q.empty() && !found){
        int sz=q.size();
        while(sz--){
            int val=q.front();
            q.pop();
            for(int die=1;die<=6;die++){
                if(val+die==100){
                    found=1;
                }
                else if(val+die<=100 && ladders[val+die] && !vis[ladders[val+die]]){
                    vis[ladders[val+die]]=1;
                    if(ladders[val+die]==100){
                        found=1;
                    }
                    q.push(ladders[val+die]);
                }
                else if(val+die<=100 && snakes[val+die] && !vis[snakes[val+die]]){
                    vis[snakes[val+die]]=1;
                    if(snakes[val+die]==100){
                        found=1;
                    }
                    q.push(snakes[val+die]);
                }
                else if(val+die <=100 && !vis[val+die] && !snakes[val+die] && !ladders[val+die] ){
                    vis[val+die]=1;
                    q.push(val+die);
                }
            }
        }
        
        moves++;
    }
    if(found){
        cout<<moves<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

/*
2
3 90
56 76
3
99 10
30 20
20 5

output:
3
*/