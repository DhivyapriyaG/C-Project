# Bus Booking System

This is Bus Booking System implemented in C. It allows users to sign up, sign in, book seats, cancel bookings, view booking history, and print bill receipts. The system also provides graphical representation of available seats on a bus.

## Features

- **User Authentication**: Users can sign up with their details and then sign in to access booking functionalities.
- **Booking Management**: Users can book multiple seats for a journey, view available seats, and cancel bookings if needed.
- **History Tracking**: Users can view their booking history, including details such as city, journey date, seat count, and status.
- **Bill Receipt Generation**: Users can generate a bill receipt for their bookings, showing total amount paid and other details.

## How It Works

1. **Sign Up**      : Users can sign up with their name, age, and password. Upon successful sign-up, a unique user ID is assigned.
2. **Sign In**: Users can sign in with their ID and password. After successful authentication, they gain access to booking functionalities.
3. **Booking**: Users can select a city, choose the number of seats to book, and select their preferred seats. The system checks seat availability and allows booking if seats are available.
4. **Cancellation**: Users can cancel their bookings by selecting the booking to cancel from their booking history. The system updates seat availability accordingly.
5. **History**: Users can view their booking history, showing details of past bookings, including city, journey date, seat count, amount paid, and status.
6. **Bill Receipt**: Users can generate a bill receipt for their bookings, showing a detailed summary of their transactions.

## Main Functions

1. `signin()`: Handles the sign-in process, including user authentication and access to booking functionalities.
2. `signup()`: Manages the sign-up process for new users, assigning unique IDs upon successful registration.
3. `bookSeat()`: Allows users to book seats for a journey, checks seat availability, and updates booking details.
4. `cancellation()`: Handles the cancellation of bookings, updating seat availability and booking status.
5. `history()`: Displays the booking history of the user, showing past bookings with relevant details.
6. `printBillReceipt()`: Generates a bill receipt for the user's bookings, showing total amount paid and other details.

## Usage

1. Clone the repository to your local machine.
2. Compile the `BusReservationSystem.c` file using a C compiler (e.g., gcc).
3. Run the compiled executable to start the Bus Booking System.
4. Follow the on-screen prompts to sign up, sign in, book seats, cancel bookings, view history, and print bill receipts.

## Contributors

- Dhivyapriya G(https://github.com/DhivyapriyaG) - Role Developer 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
