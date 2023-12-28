#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

class Vehicle;

class Trip
{
public:
    Trip(Vehicle *vehicle, std::string pick_up_location, std::string drop_location, int departure_time)
        : vehicle(vehicle), pick_up_location(pick_up_location), drop_location(drop_location), departure_time(departure_time), booked_seats(0) {}

    // Getter functions
    Vehicle *getVehicle() const
    {
        return vehicle;
    }

    std::string getPickUpLocation() const
    {
        return pick_up_location;
    }

    std::string getDropLocation() const
    {
        return drop_location;
    }

    int getDepartureTime() const
    {
        return departure_time;
    }

    int getBookedSeats() const
    {
        return booked_seats;
    }

    // Setter functions
    void setVehicle(Vehicle *v)
    {
        vehicle = v;
    }

    void setPickUpLocation(std::string location)
    {
        pick_up_location = location;
    }

    void setDropLocation(std::string location)
    {
        drop_location = location;
    }

    void setDepartureTime(int time)
    {
        departure_time = time;
    }

    void setBookedSeats(int seats)
    {
        booked_seats = seats;
    }

private:
    Vehicle *vehicle;
    std::string pick_up_location;
    std::string drop_location;
    int departure_time;
    int booked_seats;
};

class BinaryTreeNode
{
public:
    BinaryTreeNode(int departuretime = 0, Trip *tripenodeptr = nullptr, BinaryTreeNode *parentptr = nullptr)
        : leftptr(nullptr), rightptr(nullptr), parentptr(parentptr), departuretime(departuretime), tripnodeptr(tripenodeptr) {}

    // Getter functions
    BinaryTreeNode *getLeftPtr() const
    {
        return leftptr;
    }

    BinaryTreeNode *getRightPtr() const
    {
        return rightptr;
    }

    BinaryTreeNode *getParentPtr() const
    {
        return parentptr;
    }

    int getDepartureTime() const
    {
        return departuretime;
    }

    Trip *getTripNodePtr() const
    {
        return tripnodeptr;
    }

    // Setter functions
    void setLeftPtr(BinaryTreeNode *left)
    {
        leftptr = left;
    }

    void setRightPtr(BinaryTreeNode *right)
    {
        rightptr = right;
    }

    void setParentPtr(BinaryTreeNode *parent)
    {
        parentptr = parent;
    }

    void setDepartureTime(int time)
    {
        departuretime = time;
    }

    void setTripNodePtr(Trip *trip)
    {
        tripnodeptr = trip;
    }

private:
    BinaryTreeNode *leftptr;
    BinaryTreeNode *rightptr;
    BinaryTreeNode *parentptr;
    int departuretime;
    Trip *tripnodeptr;
};

class TransportService
{
public:
    TransportService(std::string name) : name(name), BSThead(nullptr) {}

    // Getter functions
    std::string getName() const
    {
        return name;
    }

    BinaryTreeNode *getBSTHead() const
    {
        return BSThead;
    }

    // Setter functions

    void setName(std::string service_name)
    {
        name = service_name;
    }

    void setBSTHead(BinaryTreeNode *node)
    {
        BSThead = node;
    }
    void Insert(BinaryTreeNode *node){

        // if (BSThead == NULL){
        //     node = BSThead;
        //     return;
        // }
        BinaryTreeNode *travel = BSThead;
        BinaryTreeNode *parent = NULL;
        while (travel != NULL){
            parent = travel;
            if (travel->getDepartureTime() > node->getDepartureTime()){
                travel = travel->getLeftPtr();
            }
            else{
                travel = travel->getRightPtr();
            }
        }

        node->setParentPtr(parent);
        if (parent->getDepartureTime() > node->getDepartureTime()){
            // travel = travel->getLeftPtr();
            parent->setLeftPtr(node);
        }
        else{
            parent->setRightPtr(node);
        }
    }

    // write here the logic of insert in BST
    void addTrip(int key, Trip *trip){
        BinaryTreeNode *node = new BinaryTreeNode(key);
        node->setTripNodePtr(trip);
        if(BSThead == NULL){

            setBSTHead(node);
        }
        else{
            Insert(node);
        }
    }

private:
    std::string name;
    BinaryTreeNode *BSThead;
};

class Vehicle
{
public:
    Vehicle(std::string vehicle_number, int seating_capacity)
        : vehicle_number(vehicle_number), seating_capacity(seating_capacity) {}

    // Getter functions
    std::string getVehicleNumber() const
    {
        return vehicle_number;
    }

    int getSeatingCapacity() const
    {
        return seating_capacity;
    }

    vector<Trip *> getTrips()
    {
        return trips;
    }

    // Setter functions
    void setVehicleNumber(std::string number)
    {
        vehicle_number = number;
    }

    void setSeatingCapacity(int capacity)
    {
        seating_capacity = capacity;
    }

    void addTrip(Trip *trip)
    {
        trips.push_back(trip);
    }

private:
    std::string vehicle_number;
    int seating_capacity;
    std::vector<Trip *> trips;
};

class Location
{
public:
    Location(std::string name) : name(name) {}

    // Getter functions
    std::string getName() const
    {
        return name;
    }

    TransportService *getServicePtr(std::string droplocation) const
    {
        for (int i = 0; i < serviceptrs.size(); i++)
        {
            if (serviceptrs[i]->getName() == droplocation)
            {
                return serviceptrs[i];
            }
        }
        return NULL;
    }
    vector<TransportService *> getServiceVector()
    {
        return serviceptrs;
    }
    // Setter functions
    void setName(std::string location_name)
    {
        name = location_name;
    }

    TransportService *setServicePtr(std::string droplocation)
    {
        TransportService *new_Service = new TransportService(droplocation);
        serviceptrs.push_back(new_Service);
        return new_Service;
    }

    void addTrip(Trip *trip)
    {
        trips.push_back(trip);
    }

private:
    std::string name;
    std::vector<TransportService *> serviceptrs;
    std::vector<Trip *> trips;
};
class BinaryTree
{
protected:
    BinaryTreeNode *root;

    int findHeight(BinaryTreeNode *root) const{
        if(root==NULL)
            return 0;
        return 1+max(findHeight(root->getLeftPtr()),findHeight(root->getRightPtr()));
    }

    int getTotalNode(BinaryTreeNode *root) const{
        if(root==NULL)
            return 0;
        return 1 + getTotalNode(root->getLeftPtr()) + getTotalNode(root->getRightPtr());
    }

public:
    BinaryTree() : root(nullptr) {}

    int getHeight() const
    {
        return findHeight(root);
    }

    int getNumberOfNodes() const
    {
        return getTotalNode(root);
    }

    void setRoot(BinaryTreeNode *root1)
    {
        this->root = root1;
    }
    BinaryTreeNode *getRoot()
    {
        return root;
    }
};

class BinarySearchTree : public BinaryTree
{
public:
    BinarySearchTree() {}

    BinaryTreeNode *getElementWithMinimumKey() const
    {
        // Implement this function to return the element with the minimum key
        if (root == nullptr){
            return nullptr;
        }
        BinaryTreeNode *current = root;
        while (current->getLeftPtr() != nullptr)
        {
            current = current->getLeftPtr();
        }

        return current;
    }

    BinaryTreeNode *getElementWithMaximumKey() const
    {
        // Implement this function to return the element with the maximum key
        if (root == nullptr){
            return nullptr;
        }
        BinaryTreeNode *current= root;
        while (current->getRightPtr() != nullptr)
        {
            current = current->getRightPtr();
        }
        return current;
    }

    BinaryTreeNode *searchNodeWithKey(int key) const
    {
        BinaryTreeNode *current = root;
        BinaryTreeNode *result = nullptr;

        while (current != nullptr)
        {
            if (key < current->getDepartureTime())
            {
                result = current; 
                current = current->getLeftPtr();
            }
            else if (key > current->getDepartureTime())
            {
                current = current->getRightPtr();
            }
            else
            {
                return current;
            }
        }
        return result;
    }

    BinaryTreeNode *getSuccessorNode(BinaryTreeNode *node) const
    {
        if (node == nullptr)
            return nullptr;
        if (node->getRightPtr() != nullptr){
            BinaryTreeNode *currentNode = node->getRightPtr();
            while (currentNode->getLeftPtr() != nullptr){
                currentNode = currentNode->getLeftPtr();
            }
            return currentNode;
        }
        else{
            BinaryTreeNode *parent = node->getParentPtr();
            while (parent != nullptr && node == parent->getRightPtr()){
                node = parent;
                parent = parent->getParentPtr();
            }
            return parent;
        }
        return nullptr;
    }

    BinaryTreeNode *getSuccessorNodeByKey(int key) const{
        BinaryTreeNode *node = searchNodeWithKey(key);
        if (node == nullptr){
            return nullptr;
        }

        BinaryTreeNode *successor = nullptr;
        if (node->getRightPtr() != nullptr){
            BinaryTreeNode *currentNode = node->getRightPtr();
            while (currentNode->getLeftPtr() != nullptr){
                currentNode = currentNode->getLeftPtr();
            }
            successor = currentNode;
        }
        else{
            BinaryTreeNode *parent = node->getParentPtr();
            while (parent != nullptr && node == parent->getRightPtr()){
                node = parent;
                parent = parent->getParentPtr();
            }
            successor = parent;
        }
        return successor;
    }

    BinaryTreeNode *getPredecessorNode(BinaryTreeNode *node) const
    {
        if (node == nullptr)
            return nullptr; 

        if (node->getLeftPtr() != nullptr){
            BinaryTreeNode *currentNode = node->getLeftPtr();
            while (currentNode->getRightPtr() != nullptr){
                currentNode = currentNode->getRightPtr();
            }
            return currentNode;
        }
        else{
            BinaryTreeNode *parent = node->getParentPtr();
            while (parent != nullptr && node == parent->getLeftPtr()){
                node = parent;
                parent = parent->getParentPtr();
            }
            return parent;
        }
        return nullptr; 
    }

    BinaryTreeNode *getPredecessorNodeByKey(int key) const{
        BinaryTreeNode *node = searchNodeWithKey(key);
        if (node == nullptr){
            return nullptr; 
        }

        BinaryTreeNode *predecessor = nullptr;
        if (node->getLeftPtr() != nullptr)
        {
            BinaryTreeNode *currentNode = node->getLeftPtr();
            while (currentNode->getRightPtr() != nullptr)
            {
                currentNode = currentNode->getRightPtr();
            }
            predecessor = currentNode;
        }
        else
        {
            BinaryTreeNode *parent = node->getParentPtr();
            while (parent != nullptr && node == parent->getLeftPtr())
            {
                node = parent;
                parent = parent->getParentPtr();
            }
            predecessor = parent;
        }

        return predecessor;
    }
};


class TravelDesk
{
public:
    void addTrip(std::string vehicle_number, int seating_capacity, std::string pick_up_location, std::string drop_location, int departure_time)
    {
        // Implement this function to add a trip
        Trip *tripPtr;
        Vehicle *vehicle = getVehicle(vehicle_number, seating_capacity);
        tripPtr = new Trip(vehicle, pick_up_location, drop_location, departure_time);
        vehicle->addTrip(tripPtr);
        getLocation(pick_up_location)->addTrip(tripPtr);
        // getLocation(pick_up_location)->getServicePtr(drop_location)->addTrip(departure_time, tripPtr);
        if (getLocation(pick_up_location)->getServicePtr(drop_location) == NULL)
        {
            getLocation(pick_up_location)->setServicePtr(drop_location)->addTrip(departure_time, tripPtr);
        }
        else
        {
            getLocation(pick_up_location)->getServicePtr(drop_location)->addTrip(departure_time, tripPtr);
        }
    }

    std::vector<Trip *> showTrips(std::string pick_up_location, int after_time, int before_time)
    {
        // Implement this function to retrieve trips within a specified time range
        vector<Trip *> tripVec;
        vector<TransportService *> newTransServ;
        bool flag = true;
        for (auto &it : locations)
        {
            if (it->getName() == pick_up_location)
            {
                newTransServ = it->getServiceVector();
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return tripVec;
        }
        for (int i = 0; i < newTransServ.size(); i++)
        {
            BinaryTreeNode *dupHead = newTransServ[i]->getBSTHead();
            BinarySearchTree *newTree = new BinarySearchTree();
            newTree->setRoot(dupHead);
            BinaryTreeNode *goingtokey = newTree->searchNodeWithKey(after_time);
            if (goingtokey == NULL)
            {
                goingtokey = newTree->getSuccessorNodeByKey(after_time);
            }
            while (goingtokey != NULL && goingtokey->getDepartureTime() < before_time)
            {
                tripVec.push_back(goingtokey->getTripNodePtr());
                goingtokey = newTree->getSuccessorNode(goingtokey);
            }
        }
        return tripVec;
        // return {}; // Placeholder
    }

    std::vector<Trip *> showTripsbydestination(std::string pick_up_location, std::string destination, int after_time, int before_time)
    {
        // Implement this function to retrieve trips within a specified time range form pickup to droplocatin
        vector<Trip *> tripVec;
        vector<TransportService *> newTransServ;
        bool flag = true;
        for (auto &it : locations)
        {
            if (it->getName() == pick_up_location)
            {
                newTransServ = it->getServiceVector();
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return tripVec;
        }
        for (int i = 0; i < newTransServ.size(); i++)
        {
            if (newTransServ[i]->getName() == destination)
            {
                BinaryTreeNode *dupHead = newTransServ[i]->getBSTHead();
                BinarySearchTree *newTree = new BinarySearchTree();
                newTree->setRoot(dupHead);
                BinaryTreeNode *goingtokey = newTree->searchNodeWithKey(after_time);
                if (goingtokey == NULL)
                {
                    goingtokey = newTree->getSuccessorNodeByKey(after_time);
                }
                while (goingtokey != NULL && goingtokey->getDepartureTime() < before_time)
                {
                    tripVec.push_back(goingtokey->getTripNodePtr());
                    goingtokey = newTree->getSuccessorNode(goingtokey);
                }
                break;
            }
        }
        return tripVec;
    }

    Trip *bookTrip(std::string pick_up_location, std::string drop_location, std::string vehicle_number, int departure_time)
    {
        // Implement this function to book a trip
        bool flag = false;
        int i;
        for (i = 0; i < locations.size(); i++)
        {
            if (locations[i]->getName() == pick_up_location)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return NULL;
        }
        for (auto &iti : locations[i]->getServiceVector())
        {
            if (iti->getName() == drop_location)
            {
                BinaryTreeNode *dupHead = iti->getBSTHead();
                BinarySearchTree *newTree = new BinarySearchTree();
                newTree->setRoot(dupHead);
                BinaryTreeNode *goingtokey = newTree->searchNodeWithKey(departure_time);
                if (goingtokey == NULL)
                    return NULL;
                if (goingtokey->getTripNodePtr()->getVehicle()->getSeatingCapacity() > goingtokey->getTripNodePtr()->getBookedSeats())
                {
                    goingtokey->getTripNodePtr()->setBookedSeats(goingtokey->getTripNodePtr()->getBookedSeats() + 1);
                    return goingtokey->getTripNodePtr();
                }
                else
                {
                    return NULL;
                }
            }
        }
        return nullptr; // Placeholder
    }

    Vehicle *getVehicle(string vehicleNum, int seating_capacity)
    {
        for (auto &it : vehicles)
        {
            if (it->getVehicleNumber() == vehicleNum)
                return it;
        }
        Vehicle *newVehicle = new Vehicle(vehicleNum, seating_capacity);
        vehicles.push_back(newVehicle);
        return newVehicle;
    }

    Location *getLocation(std::string location)
    {
        for (auto &it : locations)
        {
            if (it->getName() == location)
                return it;
        }
        Location *newLocation = new Location(location);
        locations.push_back(newLocation);
        return newLocation;
    }

private:
    std::vector<Vehicle *> vehicles;
    std::vector<Location *> locations;
};












