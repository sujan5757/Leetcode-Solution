class Solution {
public int closestMeetingNode(int[] edges, int n1, int n2) {
    int n= edges.length;
    int[] A= new int[n]; 
    int[] B= new int[n];
    Arrays.fill(A,Integer.MAX_VALUE);
    Arrays.fill(B,Integer.MAX_VALUE);
    
    bfs(n1,A,edges,n);
    bfs(n2,B,edges,n);
    
    int res= Integer.MAX_VALUE, node=-1;
    for(int i=0;i<n;i++){
        if(A[i]==Integer.MAX_VALUE || B[i]==Integer.MAX_VALUE) continue;
        if(res>Math.max(A[i],B[i])){
            node=i; 
            res= Math.max(A[i],B[i]);
        }
    }
    return node;
}
void bfs(int src, int[] dist,int[] edge,int n){
    Queue<Integer> q= new LinkedList<>();
    q.add(src);
    dist[src]=0;
    while(q.size()>0){
        var p= q.remove();
        if(edge[p]!=-1 && dist[edge[p]]==Integer.MAX_VALUE){
            q.add(edge[p]);
            dist[edge[p]]= dist[p]+1;
        }
    }
}
}
