class Solution {
    public int semiOrderedPermutation(int[] U) {
        int f=0,k=0;
        int j=U.length;
        for(int i=0;i<j;i++){
            if(U[i]==1)f=i;
        }
        int count=0;
        while(f!=0){
            int mayra=U[f];
            U[f]=U[f-1];
            U[f-1]=mayra;
            f--;
            count++;
        }
        for(int i=0;i<j;i++){
            if(U[i]==j) k=i;
        }
        return count+(j-1)-k;
        
    }
}
