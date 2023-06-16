class SnapshotArray {
public:
 int c=0;
 
 vector<map<int,int>> v;
    SnapshotArray(int length) {
         v.resize(length);
        for(int i = 0; i < length; i++)
            v[i][0] = 0;
        
    }
    
    
    void set(int index, int val) {
        v[index][c]=val;
    }
    
    int snap() {
     
        c++;
        return c-1;
    }
    
    int get(int index, int si) {
        while(v[index].find(si)==v[index].end())
        si--;
        return v[index][si];
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */