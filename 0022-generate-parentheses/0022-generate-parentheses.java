class Solution {
    List<String> res;
    
    private String listToArray(List<Character> arr){
        StringBuilder sb=new StringBuilder();
        for(Character c:arr){
            sb.append(c);
        }
        return sb.toString();
    }
    
    private void generate(List<Character> arr,int l,int r){
        if(l==0 && r==0){
            // System.out.println("asdf");
            res.add(listToArray(arr));
            return;
        }
        
        if(l>0){
            arr.add('(');
            generate(arr,l-1,r);
            arr.remove(arr.size()-1);
        }
        if(l<r){
            arr.add(')');
            generate(arr,l,r-1);
            arr.remove(arr.size()-1);
        }
    }
    
    public List<String> generateParenthesis(int n) {
        res=new ArrayList<>();
        generate(new ArrayList<>(),n,n);
        return res;
    }
}