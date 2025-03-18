# PriorityQueueLab

## 🔖 Background Information
In software engineering, a job queue is a data structure that stores a list of tasks or jobs that a computer should run (“Job Queue,” 2024). Since a computer cannot perform infinitely many tasks simultaneously, we often store the list of “todo” items in a queue, and the computer processes them as quickly as it can. There are different data structures that could work for this task, but one common way of doing it is to use a priority queue which stores information for the jobs to be run. Whenever the computer is ready to run a new job, it grabs the item with the highest priority from the queue and runs that job (making sure that it is removed from the queue afterwards).

## 🎯 Problem Statement
Implement a JobQueue class that uses a PriorityQueue under the hood to organize Job objects by their priority. I have provided you the Job class in the templates linked below.

## ✅ Acceptance Criteria
The JobQueue should implement the following methods:

void insert(Job job) - This inserts a new job into the JobQueue.
void runHighestPriority() - This calls the execute() method defined on a Job.

## 📋 Dev Notes
Let’s take a moment to break this problem down into smaller steps. Here is how I might implement the JobQueue class.

1. Create a generic MaxHeap<T> data structure. We can implement it using an array, as described in the readings and videos.
2. Create a generic class called PriorityQueue<T> that uses the MaxHeap<T> data structure to store a list of objects. You might need to utilize the Comparable interface or overload operators in order to ensure that they can be ordered correctly.
3. Create a JobQueue class which initializes a PriorityQueue<Job> in its constructor.
4. Implement the void insert(Job job) method on the JobQueue which adds Job objects to the PriorityQueue<Job>.
5. Implement the void runHighestPriority() method on the JobQueue which finds the highest priority Job, calls execute() on it, and then removes it from the PriorityQueue<Job>.

## 🖥️ Example Output
C++

```
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
jobQueue.runHighestPriority(); // Calls jobD.execute() since job C has the highest priority
jobQueue.runHighestPriority(); // Calls jobA.execute() since job C has the highest priority
jobQueue.runHighestPriority(); // Calls jobB.execute() since job C has the highest priority
jobQueue.runHighestPriority(); // Calls job1.execute() since job C has the highest priority
```

## 📝 Thought Provoking Questions
I have just one Thought Provoking Question this week, but it’s a good one 😈

Some of you might have heard of Amazon Web Services (AWS). AWS is a massive cloud platform that allows you to build and maintain a cloud infrastructure. They have a TON of different resources that you can use, including a job scheduler. Let’s read some of the docs for Amazon S3 Batch Operations (Amazon Web Services, n.d.)

This quote comes directly from the documentation on the batch ops job priority:

You can assign each Amazon S3 Batch Operations job a numeric priority, which can be any positive integer. S3 Batch Operations prioritizes jobs according to the assigned priority. Jobs with a higher priority (or a higher numeric value for the priority parameter) are evaluated first. Priority is determined in descending order. For example, a job queue with a priority value of 10 is given scheduling preference over a job queue with a priority value of 1.

This sounds like a priority queue! We literally just implemented one of those! So S3 Batch Operations is probably a glorified priority queue which stores jobs, and each job has a priority value which ranks them. Neat!

But reading onwards…

S3 Batch Operations honors job priorities on a best-effort basis. Although jobs with higher priorities generally take precedence over jobs with lower priorities, Amazon S3 doesn’t guarantee strict ordering of jobs.

So wait… it “tries its best” to order jobs? What the heck does that mean?

Let’s assume that AWS S3 Batch Operations is a priority queue under the hood. Maybe that assumption is wrong, but they strongly hint at it given their description of the service.

If it is a priority queue, why the heck does it need to “try its best” to run the highest priority job? Reflect on this apparent contradiction and give me a possible explanation as to what is going on here. Defend your argument as best you can!

Hint!

The priority queue that you implemented probably runs in a single program and processes jobs one after another in series. What happens if you start expanding to web scale where many jobs are being added to the queue and run simultaneously?

## 💼 Add-Ons For the Portfolio
N/A

## 🔗 Useful Links
C++ Project Template
Java Project Template

## 📘 Works Cited
Amazon Web Services. (n.d.). Assigning Job Priority - Amazon Simple Storage Service. Retrieved March 15, 2025, from https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops-job-priority.html
Job Queue. (2024). Wikipedia.
