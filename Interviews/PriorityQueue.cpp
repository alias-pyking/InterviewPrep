#include <vector>

/*******
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**********/


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
        int ans=pq[0];
        int min=0;
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
    while(pi<pq.size())
    {
        int lci=(2*pi)+1;
        int rci=(2*pi)+2;
        if(lci<pq.size()&&rci<pq.size())
        {
            if(pq[lci]>pq[rci])
                min=rci;
            else
                min=lci;
        }
        if(lci<pq.size()&&rci>=pq.size())
            min=lci;
        if(pq[pi]>pq[min])
        {
            int tep=pq[min];
            pq[min]=pq[pi];
            pq[pi]=tep;
            pi=min;
        }
     else 
         break;
    }
        return ans;
    }
    
    
};