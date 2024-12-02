#include <iostream>

using namespace std;


class Cutie {
        public:
        virtual string description() = 0;
        virtual int cuteness() = 0;
};

class Puppy : public Cutie {
        string description() override {
                return "A little puppy with large eyes";
        }

        int cuteness() override {
                return 7;
        }
};

class Kitty : public Cutie {
        string description() override {
                return "A small kitty with soft paws";
        }
        int cuteness() override {
                return 9;
        }
};

class Penguin : public Cutie {
        string description() override {
                return "A large penguin with a small beak";
        }
        int cuteness() override {
                return 6;
        }
};


class QueueTees {
        private:
                Cutie* q[100];
                int front;
                int rear;
                int count;
        public:
                QueueTees() {
                        front = -1;
                        rear = -1;
                        count = 0;
                }

                void enqueue(Cutie& obj) {
                        if(count == 100) {
                                cout << "The queue is full!" << endl;
                        }
                        else{
                                rear++;
                                q[rear] = &obj;
                                count++;
                        }
                }
                int size() {
                        return count;
                }

                Cutie* dequeue() {
                        if(count == 0 ) {
                                cout << "The queue is empty!" << endl;
                                return nullptr;
                        }
                        else{
                                count--;
                                front++;
                                return q[front];
                        }
                }


};

int main() {
        // Create a bunch of objects that conform to the Cutie interface
Puppy puppy;
Kitty kitty;
Penguin penguin;

// Create a queue data structure
QueueTees queue;

// The size of the queue should equal zero since there are no objects in it
cout << queue.size() << endl;

// Add the cuties to the queue
queue.enqueue(puppy);
queue.enqueue(kitty);
queue.enqueue(penguin);

// The size of the queue should equal three since there are three objects in it
cout << queue.size() << endl;

Cutie* obj1 = queue.dequeue();
// The first dequeue should return the puppy
cout << obj1->description() << endl;
obj1 = queue.dequeue();
// The second dequeue should return the kitty
cout << obj1->description() << endl;

obj1 = queue.dequeue();
// The first dequeue should return the pygmy marmoset
cout << obj1->description() << endl;

cout << queue.size() << endl;
        return 0;
}
