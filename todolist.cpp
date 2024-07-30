#include <iostream>
#include <string>
#include <vector>
using namespace std;

void menu() {
	cout << "TO-DO LIST" << endl;
	cout << "1. ADD TASK" << endl;
	cout << "2. VIEW TASK" << endl;
	cout << "3. DELETE TASK" << endl;
	cout << "4. MARK TASK AS COMPLETE" << endl;
	cout << "5. EXIT" << endl;
	cout <<"Enter task number: ";
}

void addTask(vector<string> &task, vector<bool> &complete) {
	string TASK;
	cout << "Enter task : ";
	cin.ignore();
	getline(cin, TASK);
	task.push_back(TASK);
	complete.push_back(false);
	cout << "task added \n";
}

void viewTask(vector<string> &task, vector<bool> &complete) {
	if (task.empty()) {
		cout << "No elements added , consider adding the elements" << endl;
	}
	else {
		for (int i = 0; i < task.size(); ++i) {
			cout << i + 1 << "." << task[i] << " - "<<(complete[i] ? "Completed":"Pending") << endl;
		}
	}
}

void deleteTask(vector<string> &task, vector<bool> &complete) {
	viewTask(task, complete);
	int tasknum;
	cout << "Enter task number  : ";
		cin >> tasknum;
	if (tasknum > 0 && tasknum <= task.size()) {
		task.erase(task.begin() + tasknum - 1);
		complete.erase(complete.begin() + tasknum - 1);
		cout << "Task removed\n";
	}
	else {
		cout<<"Invalid task number entered.\n";
	}
}

void markTask(vector<string> &task, vector<bool> &complete) {
	viewTask(task, complete);
	int tasknum;
	cout << "Enter task number to mark complete";
	cin >> tasknum;
	if (tasknum > 0 && tasknum <= task.size()) {
		complete[tasknum - 1] = true;
		cout << "task marked as complete \n";
	}
	else {
		cout << "invalid task number entered \n";
	}

}

int main() {
	vector<string> task;
	vector<bool> complete;
	int choice;
	while (true) {
	    menu();
	    cin>>choice;
		switch (choice) {
		case 1:
			addTask(task, complete);
			break;
		case 2:
			viewTask(task, complete);
			break;
		case 3:
			deleteTask(task, complete);
			break;
		case 4:
			markTask(task, complete);
			break;
		case 5:
			cout << "Exiting To-Do List\n";
			return 0;
		default:
			cout<<"invalid choice ,please enter again";
		}
	}
	return 0;

}