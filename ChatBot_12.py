def chatbot():

    print("Chatbot: Hello! How can I help you?")

    while True:

        user = input("You: ").lower()

        if user == "hello" or user == "hi":
            print("Chatbot: Hello! Welcome.")

        elif "price" in user:
            print("Chatbot: Prices start from Rs. 999.")

        elif "delivery" in user:
            print("Chatbot: Delivery takes 3 to 5 days.")

        elif "refund" in user:
            print("Chatbot: Refund is processed within 7 days.")

        elif "bye" in user or "exit" in user:
            print("Chatbot: Thank you! Have a nice day.")
            break

        else:
            print("Chatbot: Sorry, I did not understand.")

chatbot()
