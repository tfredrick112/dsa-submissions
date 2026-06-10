class MedianFinder {
public:
    priority_queue<int> maxHeap; // for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // for the upper half
    MedianFinder()
    {
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int, vector<int>, greater<int>>();
    }
    
    // This is O(log n) time and O(n) space
    void addNum(int num)
    {
        if (maxHeap.empty())
        {
            maxHeap.push(num);
        }
        else
        {
            if (maxHeap.top() >= num)
            {
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }

            //rebalancing
            int minHeapSize = minHeap.size();
            int maxHeapSize = maxHeap.size();
            if (minHeapSize - maxHeapSize > 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if (maxHeapSize - minHeapSize > 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    // O(1) time and space
    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return (minHeap.top() + maxHeap.top())/2.0;
        }
        else
        {
            return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
        }
    }
};
