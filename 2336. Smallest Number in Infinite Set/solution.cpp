/*
121 ms
47.7 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : SET
*/

class SmallestInfiniteSet {
private:
    set<int>s;
public:
    SmallestInfiniteSet() {
        for(int i=1; i<= 1001; i++){
            s.emplace(i);
        }
    }
    
    int popSmallest() {
        int top = *s.begin();
        s.erase(s.begin());
        return top;
    }
    
    void addBack(int i) {
        s.emplace(i);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */