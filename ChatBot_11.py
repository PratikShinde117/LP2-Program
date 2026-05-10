def chatbot():

    print("===================================")
    print(" Welcome to Customer Support Chat ")
    print("===================================")

    print("Type 'bye' to exit.\n")

    while True:

        user = input("You: ").lower()

        # Greeting
        if "hello" in user or "hi" in user:
            print("Bot: Hello! How can I help you?")

        # Product Information
        elif "product" in user:
            print("Bot: We provide laptops, smartphones, and accessories.")

        elif "price" in user:
            print("Bot: Product prices start from Rs. 999.")

        elif "features" in user:
            print("Bot: Our products include latest features and warranty support.")

        # Service Details
        elif "service" in user:
            print("Bot: We provide repair and maintenance services.")

        elif "delivery" in user:
            print("Bot: Delivery usually takes 3 to 5 business days.")

        elif "refund" in user:
            print("Bot: Refunds are processed within 7 working days.")

        elif "warranty" in user:
            print("Bot: All products come with 1 year warranty.")

        # FAQs
        elif "payment" in user:
            print("Bot: We accept UPI, Debit Card, Credit Card, and Net Banking.")

        elif "contact" in user:
            print("Bot: You can contact us at support@example.com.")

        elif "location" in user:
            print("Bot: Our main office is located in Pune.")

        # Exit
        elif "bye" in user or "exit" in user:
            print("Bot: Thank you for visiting. Have a nice day!")
            break

        # Default Response
        else:
            print("Bot: Sorry, I could not understand your query.")

chatbot()
