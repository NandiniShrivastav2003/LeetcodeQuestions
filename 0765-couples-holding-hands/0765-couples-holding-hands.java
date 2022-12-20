class Solution {
    public int minSwapsCouples(int[] row) {
int i=0; int count = 0;
int[] pos = new int[row.length];

    for(int j=0;j<pos.length;j++){
        pos[row[j]] = j;
    }
    
    while(i<row.length-1){
        if(row[i] % 2 == 0 && row[i+1] != row[i]+1){
            swap(row, pos, i+1, pos[row[i]+1]);
            count++;
        }
        else if(row[i] % 2 != 0 && row[i+1] != row[i]-1){
            swap(row, pos, i+1, pos[row[i]-1]);
            count++;
        }
        else
            i = i+2;

    }
    return count;
}

public void swap(int[] arr, int[] pos, int i, int j){
    int temp = arr[i];
    pos[temp] = j;
    arr[i] = arr[j];
    pos[arr[j]] = i;
    arr[j] = temp;
}
    
}