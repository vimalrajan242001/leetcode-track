public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length){
            return false;
        }

        Dictionary<char, int> store = new Dictionary<char, int>();


        foreach(char schar in s){
            if(!store.ContainsKey(schar)){
                store[schar] = 1;
            }
            else{
                store[schar]++;
            }
        }

        foreach (char tchar in t){
            if(store.ContainsKey(tchar) && store[tchar]>0){
                store[tchar]--;
            }
            else{
                return false;
            }

        }

        return true;
    }
}