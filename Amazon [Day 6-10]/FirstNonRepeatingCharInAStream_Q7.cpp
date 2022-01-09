class Solution {
        
		/*
		    Observation:
		    Case: aabcbd
		    O/P:  a#bbcc
		    We have a stream of characters incoming and 
		    we need to maintain a list kindof thing where we need to perform following operations:
		    1. if the incoming character isn't in the list, add it
		    2. if the character already exists, remove it from the list
		    3. while maintaining the order in which these characters are appearing
		    
		    So we can use a Doubly Linked List or deque for the purpose 
		    however, we might need to delete some character from random position
		    hence using deque isn't feasible.
		    
		    Logic:
		    1. Create LL with dummy nodes head & tail with next and previous pointers.
		    2. Make a add function to add new character at the tail
		    3. Make delete function to delete the node at any random address
		    4. We'll also be storing the addresses of each node in a hash array
		    5. also we'll need a frequency array to check if the character is repeated
		    6. the front of the DLL after conducting operations for each incoming character will be 
		       the 1st non repeating character in that stream
		   
		  Traversing stream- N
		  {
		      Adding- O(1)
		      Deleting- O(1)
		      Getting 1st non-repeating character- O(1)
		  }
		  
		  TC: O(N)
		  SC: O(N)
		*/
		
    public:
        
        class node
        {
            public:
            char ch;
            node* next, *prev;
            node( char _ch)
            {
                ch= _ch;
            }
        };

        node *head= new node('#');
        node *tail= new node('#');
        
        //constructor to initialize DLL
        Solution()
        {
            head->next= tail;
            tail->prev= head;
        }
        
        //function to add node just before tail
        void addNode(node* newnode)
        {
            node* prevnode= tail->prev;
            newnode->prev= prevnode;
            newnode->next=tail;
            prevnode->next= newnode;
            tail->prev= newnode;
        }
        
        //function to delete the node
        void deleteNode(node *delnode)
        {
            node *delprev= delnode->prev;
            node *delnext= delnode->next;
            delprev->next= delnext;
            delnext->prev= delprev;
        }
        
        char firstNonRepChar()
        {
            return (head->next)->ch;
        }
        
		string FirstNonRepeating(string A)
		{
    		int n= A.length();
    		string ans="";
            vector<node*> hash(26,NULL);
            int repeated[26]={0};
            
    		for(int i=0; i<n; i++)
    		{
    		    node* u= new node(A[i]);
                
    		    //doen't exists already
    		    if( repeated[A[i]-'a']==0 ) 
    		    {
    		        addNode(u);
        		    hash[A[i]-'a']= u;
    		    }
    		    else
    		    {
    		        if(hash[A[i]-'a']!=NULL)
        		    {
        		        deleteNode(hash[A[i]-'a']);
        		        hash[A[i]-'a']= NULL;
        		    }
    		    }
    		    
    		   repeated[A[i]-'a']=1;
    		   ans+= firstNonRepChar();
    		}
    		
    		
    		return ans;
		}