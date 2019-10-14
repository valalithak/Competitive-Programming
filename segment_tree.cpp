#include<iostream>
#include<vector>
using namespace std;

long long int a1[200002];
long long int diff1[800008];
long long int segtree[800008];
long long int stren[200002], node[200002];
long long int n,m,q;
long long int arrange[300003];
long long int t=0;
long long int dis[200002],st[200002],ft[200002],flag[200002],baseseg[800002];
bool visited[200002];
long long int identify[200002],lazy[200002];
int flagger;

vector<long long int>adj[200002];

void dfs(long long int u){
        t++;
        st[u]=t;
        arrange[t]=u;




        visited[u]=true;
        flag[u]=1;

        for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];

                if(flag[v]==0)
                        dis[v]=dis[u]+1;



                if(visited[v]==false)
                        dfs(v);}

        t++;
        ft[u]=t;
        arrange[t]=u;




}



void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        
        segtree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        
        segtree[node] += (end - start + 1) * diff1[node]*val*flagger;
        if(start != end)
        {
            
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   
    segtree[node] = segtree[node*2] + segtree[node*2+1];         
}







long long int build(long long int arr[],long long int ss,long long int se,long long int si,long long int st[]){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }

long long int mid=(ss+se)/2;
st[si]=build(arr,ss,mid,2*si,st)+build(arr,mid+1,se,2*si+1,st);
 return st[si];
}

long long int build2(long long int arr[],long long int ss,long long int se,long long int si,long long int st[]){
    if(ss==se){
        st[si]=arr[ss];
        identify[arr[ss]]=si;
        return arr[ss];
    }

long long int mid=(ss+se)/2;
st[si]=build2(arr,ss,mid,2*si,st)+build2(arr,mid+1,se,2*si+1,st);
 return st[si];
}


int main(){

    long long int x,y,node,value,base[200002],mainstrength[200002];
cin>>n>>m;


for(int i=1;i<=n;i++){
    cin>>stren[i];
    base[i]=i;
}

for(int i=1;i<n;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

dfs(1);

for(int i=1;i<=t;i++){
    mainstrength[i]=stren[arrange[i]];
    if(dis[arrange[i]]%2==0){
        a1[i]=1;
    }
    else{
        a1[i]=-1;
    }

}
    build(a1,1,t,1,diff1);
    build(mainstrength,1,t,1,segtree);
    build2(arrange,1,t,1,baseseg);
    int type;

for(int i=0;i<m;i++){
cin>>type;
if(type==1){
    cin>>node>>value;
    if(a1[node]==1)
        flagger=1;
    else
        flagger=-1;
    updateRange(1,1,2*n,st[node],ft[node],value);
}


    if(type==2){
        cin>>node;
    cout<<segtree[identify[node]]<<endl;
}
}

return 0;
}

