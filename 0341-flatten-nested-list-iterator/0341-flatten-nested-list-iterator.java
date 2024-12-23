/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private List<Integer> curr;
    private int index=0;
    
    private List<Integer> getList(List<NestedInteger> lis){
        List<Integer> curr=new ArrayList<>();
        int len=lis.size();
        
        for(int i=0;i<len;++i){
            if(lis.get(i).isInteger()){
                curr.add(lis.get(i).getInteger());
            }
            else{
                curr.addAll(getList(lis.get(i).getList()));
            }
        }
        
        return curr;
    }
    
    public NestedIterator(List<NestedInteger> nestedList) {
        curr=getList(nestedList);
    }

    @Override
    public Integer next() {
        return curr.get(index++);
    }

    @Override
    public boolean hasNext() {
        return index<curr.size();
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */