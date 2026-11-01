/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        int minr=0 , maxr=m-1;
        int minc=0 , maxc=n-1;
        ListNode* temp=head;
        while(temp != NULL){
            for(int j=minc;j<=maxc;j++){
                if(temp==NULL) break;
                arr[minr][j]=temp->val;
                temp=temp->next;
            }
            minr++;
            if(temp==NULL) break;
            for(int i=minr;i<=maxr;i++){
                if(temp==NULL) break;
                arr[i][maxc]=temp->val;
                temp=temp->next;
            }
            maxc--;
            if(temp==NULL) break;
            for(int j=maxc;j>=minc;j--){
                if(temp==NULL) break;
                arr[maxr][j]=temp->val;
                temp=temp->next;
            }
            maxr--;
            if(temp==NULL) break;
            for(int i=maxr;i>=minr;i--){
                if(temp==NULL) break;
                arr[i][minc]=temp->val;
                temp=temp->next;
            }
            minc++;
        }
        return arr;
        
    }
};