#include <iostream>

namespace blackjack {

    /* 4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля:
     * масть, значение карты и положение карты (вверх лицом или рубашкой).
     * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
     * Также в этом классе должно быть два метода:
     * - метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее
     * поворачивает лицом вверх, и наоборот.
     * - метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
     */

    //масть карты (червы, бубны, трефы, пики)
    enum Suit { Hearts, Diamonds, Clubs, Spades };

    //значение карты
    enum CardValue : int {
        //2-10
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
        Ten = 10,

        //валет, дама, король
        Jack = 10,
        Queen = 10,
        King = 10,

        //туз
        Ace = 1
    };

    class Card {
    private:
        Suit suit;
        CardValue cardValue;
        bool isFlipped;

        std::string suitToString(Suit suit) {
            switch(suit)
            {
                case Spades:   return "Spades";
                case Hearts:   return "Hearts";
                case Diamonds: return "Diamonds";
                case Clubs:    return "Clubs";
                default:       return "";
            };
        }

    public:
        Card(Suit suit, CardValue cardValue, bool isFlipped)
        : suit(suit), cardValue(cardValue), isFlipped(isFlipped) {
        }

        Card(Suit suit, CardValue cardValue)
        : suit(suit), cardValue(cardValue), isFlipped(false) {
        }

        void flip() {
            isFlipped = !isFlipped;
        }

        const int getValue() {
            return cardValue;
        }

        std::string toString() {
            return "SUIT: " + suitToString(suit) + ", VALUE: " + std::to_string(cardValue)
            + ", is flipped: " + std::to_string(isFlipped);
        }
    };

    // ================ Тестирование ================

    void cardTest() {
        Card cardAce(Suit::Spades, CardValue::Ace);
        std::cout << cardAce.toString() << std::endl;

        cardAce.flip();
        std::cout << cardAce.toString() << std::endl;

        Card cardQueen(Suit::Diamonds, CardValue::Queen, true);
        std::cout << cardQueen.toString() << std::endl;
        cardQueen.flip();
        std::cout << cardQueen.toString() << std::endl;
    }

    void run() {
        std::cout << "Blackjack test:" << std::endl;
        cardTest();
    }
}