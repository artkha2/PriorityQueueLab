#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Job {
  string name;
  int priority;

public:
  Job(string n, int p) : name(n), priority(p) {}

  void execute() {
    cout << "Running the job with name " << name << " and priority " << priority;
  }

  string getName() const {
    return name;
  }

  int getPriority() const {
    return priority;
  }

  // overload the greater than operator
  bool operator>(const Job& other) const {
    return getPriority() > other.getPriority();
}
};

// HeapPriorityQueue class that implements a priority queue with a max-heap as an underlying data structure using a vector
template <typename Entry, typename Compare=greater<Entry>>
class HeapPriorityQueue {
    vector<Entry> data;  // underlying collection
    Compare greater_than;  // greater_than(a,b) defines "a > b" relationship

    int parent(int j) { return (j-1) / 2; }  // calculations use the vector indices
    int left(int j) { return 2 * j + 1; }  // left child
    int right(int j) { return 2 * j + 2; }  // right child
    bool has_left(int j) { return left(j) < data.size(); }
    bool has_right(int j) { return right(j) < data.size(); }
    
    // Moves the entry at index j higher, if necessary, to restore the heap property
    void upheap(int j) {
        while (j > 0) {  // continue to root (or break statement)
            int p{parent(j)};
            if (greater_than(data[j], data[p])) {  // if j's entry is greater than its parent
                swap(data[j], data[p]);  // swap j with parent
                j = p;  // continue from new location after the swap
            } else
                break;  // j is properly placed relative to parent
        }
    }
    
    // Moves the entry at index j lower, if necessary, to restore the heap property
    void downheap(int j) {
        while (has_left(j)) {  // continue to bottom (or break statement)
            int big_child{left(j)};  // default big child is on the left
            if (has_right(j) && (greater_than(data[right(j)], data[left(j)]))) {  // if there is a right child and it is greater than the left
                big_child = right(j);  // big child is actually the right one
            }

            if (greater_than(data[big_child], data[j])) {  // if big child's entry is greater than j's
                swap(data[j], data[big_child]);  // swap the j with child
                j = big_child;  // continue from new location after the swap
            } else
                break;
        }
    }

  public:
    HeapPriorityQueue() {}  // default is an empty priority queue

    int size() const { return data.size(); }  // returns number of entries
    bool empty() const { return data.empty(); }  // returns true if zero entries
    const Entry& max() const { return data.front(); }  // returns reference to root entry

    // Inserts a new entry into the priority queue
    void insert(const Entry& e) {
        data.push_back(e);  // add to the end of the vector
        upheap(data.size() - 1);  // upheap newly added entry
    }
    
    // Removes the maximum entry
    void remove_max() {
        swap(data[0], data[data.size() - 1]);  // put last entry at the root
        data.pop_back();  // and remove the displaced maximum
        downheap(0);  // fix heap property for new root
    }
};


// Wrapper around HeapPriorityQueue for Job objects
class JobQueue {
    HeapPriorityQueue<Job> queue;

public:
    JobQueue() = default;  // default constructor for queue

    // Adds a job to the priority queue
    void insert(const Job job) {
        queue.insert(job);
    }

    // Retrieves, removes, and runs the highest-priority job
    void runHighestPriority() {
        if (queue.empty()) {
            return;
        }
        auto nextJob = queue.max();
        nextJob.execute();
        queue.remove_max();
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return queue.empty();
    }

    // Get the number of jobs in the queue
    int size() const {
        return queue.size();
    }
};

int main(){
    JobQueue jobQueue;
 
    Job jobA("This is job a", 5);
    Job jobB("This is job b", 2);
    Job jobC("This is job c", 9);
    Job jobD("This is job d", 8);
    Job jobE("This is job e", 1);
    jobQueue.insert(jobA);
    jobQueue.insert(jobB);
    jobQueue.insert(jobC);
    jobQueue.insert(jobD);
    jobQueue.insert(jobE);
    
    jobQueue.runHighestPriority(); // Calls jobC.execute() since job C has the highest priority
    cout << endl;
    jobQueue.runHighestPriority(); // Calls jobD.execute() since job D has the highest priority
    cout << endl;
    jobQueue.runHighestPriority(); // Calls jobA.execute() since job A has the highest priority
    cout << endl;
    jobQueue.runHighestPriority(); // Calls jobB.execute() since job B has the highest priority
    cout << endl;
    jobQueue.runHighestPriority(); // Calls jobE.execute() since job E has the highest priority
}