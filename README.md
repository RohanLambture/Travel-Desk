Problem Description: Transportation Management System

You are tasked with designing a Transportation Management System to facilitate the scheduling and booking of trips for a fleet of vehicles. The system comprises several classes to represent vehicles, trips, locations, and services. Your goal is to implement various functionalities related to trip scheduling, retrieval, and booking.

The system has the following main components:

1. Vehicle Class:
   - Represents a vehicle with a unique vehicle number and seating capacity.
   - Stores information about the trips associated with the vehicle.

2. Trip Class:
   - Represents a scheduled trip with details such as the associated vehicle, pick-up and drop-off locations, departure time, and the number of booked seats.
   - Allows booking additional seats for the trip.

3. Location Class:
   - Represents a geographical location (pick-up or drop-off point) with a unique name.
   - Stores information about the services available at the location and the trips associated with those services.

4. TransportService Class:
   - Represents a transportation service that operates between two locations.
   - Maintains a Binary Search Tree (BST) to organize and search for trips based on departure times efficiently.

5. TravelDesk Class:
   - Manages the overall transportation system.
   - Provides functionalities to add trips, retrieve trips within a specified time range, and book seats for trips.

6. BinarySearchTree Class:
   - Extends the BinaryTree class and represents a Binary Search Tree used to organise and search for trips based on departure times.
   - Implements methods to find the minimum and maximum key nodes, search for nodes with a specific key, and find successor and predecessor nodes.

Your task is to implement the necessary functionalities for adding trips, retrieving trips based on different criteria, and booking seats. Additionally, ensure that the system efficiently organizes and searches for trips using the Binary Search Tree structure.

Functionality Overview:

1. Add Trip:
   - Add a new trip to the system, associating it with the appropriate vehicle, pick-up, and drop-off locations.

2. Show Trips:
   - Retrieve and display trips within a specified time range.

3. Show Trips by Destination:
   - Retrieve and display trips within a specified time range from a pick-up location to a specific drop-off location.

4. Book Trip:
   - Book seats for a specified trip, ensuring that the number of booked seats does not exceed the seating capacity of the associated vehicle.

Classes and Relationships:

- Each vehicle has multiple trips associated with it.
- Each location has multiple services, and each service has a BST to organize trips.
- The TravelDesk manages the overall system, including vehicles, locations, and services.
