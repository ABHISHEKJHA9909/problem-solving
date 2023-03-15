class Solution {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        q.add(root);
        int cnt=1, i=1;
        
        while(q.size()!=0){
            // if(cnt!=i)
            //     break;
            
            cnt=0;
            boolean b=false;
            for(int j=0,n=q.size();j<n;j++){
                root=q.poll();
                if(root.right==null||root.left==null){
                    b=true;
                }
                q.add(root.left);
                q.add(root.right);
            }
            
            if(b){
                // System.out.println(q.peek().val);
                while(q.peek()!=null){
                    root=q.poll();
                    if(root.left!=null || root.right!=null)
                        return false;
                }
                while(q.size()!=0){
                    if(q.poll()!=null)
                        return false;
                }
            }
            
            i<<=1;
        }
        
        
        
        return true;
    }
}