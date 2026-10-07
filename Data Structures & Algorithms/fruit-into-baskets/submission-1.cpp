class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int f1 = fruits[0], f2 = -1;
        int f1ind = 0, f2ind = -1;
        int total = 1, ans = 1, l = 0;

        for (int r = 0; r < fruits.size(); r++) {
            if (f1 == fruits[r]) {
                f1ind = r;
                total++;
            } else if (f2 == fruits[r] || f2 == -1) {
                f2ind = r;
                f2 = fruits[r];
                total++;
            } else {
                if (f2ind == min(f1ind, f2ind)) {
                    swap(f1ind, f2ind);
                    swap(f1, f2);
                }
                total -= (f1ind - l + 1);
                l = f1ind + 1;
                f1 = fruits[r];
                f1ind = r;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};