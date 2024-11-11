#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

// defining structure _
struct Product
{
    int product_id;
    string product_name;
    string category;
};
struct Order
{
    int order_id;
    int product_id;
    int quantity;
    string customer_id;
    time_t order_date;
};

int main()
{
    // creating a vector of Product
    vector<Product> products = {
        {1, "Laptop", "Electronics"},
        {2, "Smartphone", "Electronics"},
        {3, "Headphones", "Electronics"},
        {4, "Shirt", "Clothing"},
        {5, "Pants", "Clothing"},
        {6, "Shoes", "Clothing"},
        {7, "Book", "Books"},
        {8, "Magazine", "Books"},
        {9, "Newspaper", "Books"},
        {10, "Tablet", "Electronics"}};

    deque<string> recentCustomers = {
        "C001",
        "C002",
        "C003",
    };
    recentCustomers.push_back("C004");
    recentCustomers.push_back("C005");

    // place order
    list<Order> orderHistory;
    orderHistory.push_back(Order{1, 1, 2, "C001", time(0)});
    orderHistory.push_back(Order{2, 2, 1, "C002", time(0)});
    orderHistory.push_back(Order{3, 3, 1, "C003", time(0)});

    //
    set<string> categories;
    for (const auto &product : products)
    {
        categories.insert(product.category);
    }
    //
    map<int, int> productStock = {
        {1, 10},
        {2, 20},
        {3, 30},
        {4, 40},
        {5, 50},
        {6, 60},
        {7, 70},
        {8, 80},
        {9, 90},
        {10, 100}

    };
    multimap<string, Order> customerOrders;
    for (auto &order : orderHistory)
    {
        customerOrders.insert({order.customer_id, order});
    }

    unordered_map<string, string> customerData = {
        {"C001", "John"},
        {"C002", "Jane"},
        {"C003", "Bob"},
        {"C004", "Alice"},
        {"C005", "Charlie"}};

    unordered_set<int> uniqueProductIDs;
    for (const auto &order : orderHistory)
    {
        uniqueProductIDs.insert(order.product_id);
    }
    // print customer data
    cout << "Customer Data:" << endl;
    for (const auto &customer : customerData)
    {
        cout << customer.first << ": " << customer.second << endl;
    }
    // Print product information
    cout << "Products:" << endl;
    for (const auto &product : products)
    {
        cout << product.product_id << ": " << product.product_name << " (" << product.category << ")" << endl;
    }

    // Print order history
    cout << "Order History:" << endl;
    for (const auto &order : orderHistory)
    {
        cout << "Order ID: " << order.order_id << ", Product ID: " << order.product_id << ", Quantity: " << order.quantity << ", Customer ID: " << order.customer_id << endl;
    }

    // Print categories
    cout << "Categories:" << endl;
    for (const auto &category : categories)
    {
        cout << category << endl;
    }

    // Print product stock
    cout << "Product Stock:" << endl;
    for (const auto &stock : productStock)
    {
        cout << "Product ID: " << stock.first << ", Stock: " << stock.second << endl;
    }
    return 0;
}
