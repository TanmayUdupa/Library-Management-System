#include <iostream>
#include <algorithm>
using namespace std;

//Structure to store information of a particular book
struct book
{
	int id {0};
	int added1 {0};
	string name {""};
	int quantity {0};
	int borrowed {0};
	string username[100] {""};
};

//Structure to store information of a library member
struct user
{
	int user_id {0};
	int added2 {0};
	string user_name {""};
	string Address {""};
	string email {""};
	int book_id[100] {0};
	string book_name[100] {""};
};

//Checks if id of first book is less than id of second book. Used later while calling sort() function
bool compare1(book &a, book &b)
{
	if (a.id < b.id)
	{
		return true;
	}

	return false;
}

//Checks if name of first book comes before name of second book. Used to sort books in alphabetical order later by calling sort() function
bool compare2(book &a, book &b)
{
	if (a.name < b.name)
	{
		return true;
	}

	return false;
}

//Checks if id of first user is less than id of second user. Used later while calling sort() function
bool compare3(user &a, user &b)
{
	if (a.user_id < b.user_id)
	{
		return true;
	}

	return false;
}

//Checks if name of first user comes before name of second user. Used to sort books in alphabetical order later by calling sort() function
bool compare4(user &a, user &b)
{
	if (a.user_name < b.user_name)
	{
		return true;
	}

	return false;
}

//Function to add books in the library
void add_book(int id, string name, int quantity, book &b)
{
	b.id = id;
	b.name = name;
	b.quantity = quantity;
}

//Function to search a book in the library
bool search_book(string prefix, book &b)
{
	int p = prefix.size();
	bool b1 {1};

	for (int j {0}; j < p; j++)
	{
		if (b.name[j] != prefix[j])
		{
			b1 = 0;
		}
	}

	return b1;
}

//Function that prints the names of the users who borrowed the book
void who_borrowed(book &b)
{
	for (int i {0}; i < 100; i++)
	{
		if (b.username[i] == "")
		{
			break;
		}

		cout << b.username[i] << endl;
	}
}

//Function that prints the information of the book
void print_library(book &b)
{
	cout << "id = " << b.id << " name = " << b.name;
	cout << " total_quantity " << b.quantity;
	cout << " total_borrowed " << b.borrowed << endl;
}

//Function to add a library member to the library
void add_user(string user_name, int user_id, string Address, string email, user &u)
{
	u.user_name = user_name;
	u.user_id = user_id;
	u.Address = Address;
	u.email = email;
}

//Function to print information of the user
void print_user(user &u)
{
	cout << "user " << u.user_name << " id " << u.user_id;
	cout << " email " << u.email << " address " << u.Address;
	cout << " borrowed books ids: ";
	for (int i {0}; i < 100; i++)
	{
		if (u.book_id[i] == 0)
		{
			break;
		}

		cout << u.book_id[i] << " ";
	}
	cout << endl;
}

//Function that prints the books that were borrowed by the user
void list_borrowed(user &u)
{
	for (int i {0}; i < 100; i++)
	{
		if (u.book_name[i] == "")
		{
			break;
		}

		cout << u.book_name[i] << endl;
	}
}

//Function that is called when a user has borrowed a book
void borrow(user &u, book &b)
{
	//Checks whether all the copies of the book are borrowed or not
	if (b.quantity == 0)
	{
		cout << "Book not available\n";
	}

	u.book_id[u.added2] = b.id;
	u.book_name[u.added2] = b.name;
	u.added2++;
	b.quantity--;
	b.borrowed++;
	b.username[b.added1] = u.user_name;
	b.added1++;
}

//Function that is called when a user has returned a book
void return_book(user &u, book &b)
{
	for (int i {0}; i <= u.added2; i++)
	{
		if (u.book_id[i] == b.id)
		{
			u.book_id[i] = 0;
			u.book_name[i] = "";
			for (int j {i + 1}; j <= u.added2; j++)
			{
				int temp1 = u.book_id[j];
				u.book_id[j] = u.book_id[j - 1];
				u.book_id[j - 1] = temp1;
				string temp2 = u.book_name[j];
				u.book_name[j] = u.book_name[j - 1];
				u.book_name[j - 1] = temp2;
			}
			u.added2--;
			break;
		}
	}

	b.quantity++;
	b.borrowed--;

	for (int i {0}; i <= b.added1; i++)
	{
		if (b.username[i] == u.user_name)
		{
			b.username[i] = "";
			for (int j {i + 1}; j <= b.added1; j++)
			{
				string temp = b.username[j];
				b.username[j] = b.username[j - 1];
				b.username[j - 1] = temp;
			}
			b.added1--;
			break;
		}
	}
}

int main()
{
	book B[100] {};
	user U[100] {};
	int added3 {0};
	int added4 {0};
	int choice {};
	int id {}, quantity {}, count {0}, count1 {0}, count2 {0};;
	string bookname {}, username {}, prefix {}, address {}, email{};

	cout << "Library menu:\n";
	cout << "1) add_book\n2) search_books_by_prefix\n";
	cout << "3) print_who_borrowed_book_by_name\n";
	cout << "4) print_library_by_id\n5) print_library_by_name\n";
	cout << "6) add_user\n7) user_borrow_book\n";
	cout << "8) user_return_book\n9) print_what_books_user_borrowed\n";
	cout << "10) print_users_by_id\n11) print_users_by_name\n";
	cout << "12) Exit\n\n";

	//Below loop keeps running until and unless the user enters 12 as choice
	do
	{
		cout << "Enter your menu choice [1 - 12]: ";
		cin >> choice;

		switch(choice)
		{
		//Add books
		case 1:
			cout << "Enter book info: id & name & total quantity: ";
			cin >> id >> bookname >> quantity;
			add_book(id, bookname, quantity, B[added3]);
			added3++;
			break;

		//Search a book
		case 2:
			cout << "Enter book name prefix: ";
			cin >> prefix;
			count = 0;
			for (int i {0}; i <= added3; i++)
			{
				if (search_book(prefix, B[i]))
				{
					cout << B[i].name << endl;
					count++;
				}
			}

			//Condition that is true when none of the names of the books have the prefix entered
			if (count == 0)
			{
				cout << "No books with such prefix\n";
			}
			break;

		//Display a list of users who have borrowed a particular book
		case 3:
			cout << "Enter book name: ";
			cin >> bookname;
			count = 0;
			for (int i {0}; i <= added3; i++)
			{
				if (B[i].name == bookname)
				{
					//Condition that is true when the book hasn't been borrowed
					if (B[i].borrowed == 0)
					{
						cout << "No one borrowed this book\n";
						count = 1;
						break;
					}
					count++;
					who_borrowed(B[i]);
					break;
				}
			}

			//Condition to check if user has entered a valid name or not
			if (count == 0)
			{
				cout << "Invalid book name.\n";
			}
			break;

		//Print the details of all the books in the library in ascending order of their id
		case 4:
			//sort() is an in-built function. Here it is used to sort the books in order of their ids
			sort(B, B + added3, compare1);

			cout << endl;
			for (int i {0}; i < added3; i++)
			{
				print_library(B[i]);
			}
			break;

		//Print the details of all the books in the library in alphabetical order
		case 5:
			//Here, sort() function sorts the books in alphabetical order
			sort(B, B + added3, compare2);

			cout << endl;
			for (int i {0}; i < added3; i++)
			{
				print_library(B[i]);
			}
			break;

		//Add details of new library member
		case 6:
			cout << "Enter user name & national id & email & address: ";
			cin >> username >> id >> email >> address;
			add_user(username, id, address, email, U[added4]);
			added4++;
			break;

		//User has borrowed a book
		case 7:
			cout << "Enter user name and book name: ";
			cin >> username >> bookname;

			for (int i {0}; i <= added3; i++)
			{
				if (B[i].name == bookname)
				{
					count1++;
					for (int j {0}; j <= added4; j++)
					{
						if (U[j].user_name == username)
						{
							count2++;
							borrow(U[j], B[i]);
							break;
						}
					}
					break;
				}
			}

			if (count1 == 0)
			{
				cout << "Invalid book name\n";
			}
			if (count2 == 0)
			{
				cout << "Invalid user name\n";
			}
			break;

		//User has returned a book
		case 8:
			cout << "Enter user name and book name: ";
			cin >> username >> bookname;
			for (int i {0}; i <= added3; i++)
			{
				if (B[i].name == bookname)
				{
					count1++;
					for (int j {0}; j <= added4; j++)
					{
						if (U[j].user_name == username)
						{
							count2++;
							return_book(U[j], B[i]);
							break;
						}
					}
					break;
				}
			}

			if (count1 == 0)
			{
				cout << "Invalid book name\n";
			}
			if (count2 == 0)
			{
				cout << "Invalid user name\n";
			}
			break;

		//Display the books that a user has borrowed
		case 9:
			cout << "Enter user name: ";
			cin >> username;
			count = 0;
			for (int i = 0; i <= added4; i++)
			{
				if (U[i].user_name == username)
				{
					if (U[i].book_id[0] == 0)
					{
						cout << "User has not borrowed any book\n";
						count = 1;
						break;
					}
					count++;
					list_borrowed(U[i]);
					break;
				}
			}
			if (count == 0)
			{
				cout << "Invalid user name.\n";
			}
			break;

		//Print all the library members in order of their ids
		case 10:
			sort(U, U + added4, compare3);
			cout << endl;
			for (int i {0}; i < added4; i++)
			{
				print_user(U[i]);
			}
			break;

		//Print all the library members in alphabetical order
		case 11:
			sort(U, U + added4, compare4);
			cout << endl;
			for (int i {0}; i < added4; i++)
			{
				print_user(U[i]);
			}
			break;

		//Exit the program
		case 12:
			return 0;
			break;

		default:
			cout << "Invalid choice!!!\n";
		}
	}while (true);

	return 0;
}
