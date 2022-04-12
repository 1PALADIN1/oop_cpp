#include <vector>
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

    const int ACE_MAX_VALUE = 11;
    const int TOTAL_SCORE = 21;

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

        CardValue getValue() const {
            return cardValue;
        }

        std::string toString() {
            return "SUIT: " + suitToString(suit) + ", VALUE: " + std::to_string(cardValue)
            + ", is flipped: " + std::to_string(isFlipped);
        }
    };

    /* ЗАДАНИЕ К УРОКУ 4 */
    /*
     * 3. Реализовать класс Hand, который представляет собой коллекцию карт.
     * В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический
     * массив, а тип его элементов должен быть - указатель на объекты класса Card).
     * Также в классе Hand должно быть 3 метода:
     * • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
     * • метод Clear, который очищает руку от карт
     * • метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
     */

    class Hand {
    private:
        std::vector<Card*> cards;

    public:
        void add(Card *card) {
            cards.push_back(card);
        }

        void clear() {
            std::vector<Card*>::iterator iter = cards.begin();
            for (iter = cards.begin(); iter != cards.end(); ++iter) {
                delete *iter;
                *iter = 0;
            }

            cards.clear();
        }

        int getTotal() const {
            int sum = 0;
            for (Card* card : cards) {
                sum += card->getValue() == CardValue::Ace ? ACE_MAX_VALUE : card->getValue();
            }

            if (sum > TOTAL_SCORE) {
                //пробуем пересчитать, где тузы = 1
                sum = 0;
                for (Card* card : cards) {
                    sum += card->getValue();
                }
            }

            return sum;
        }
    };

    /* ЗАДАНИЕ К УРОКУ 5 */
    /*
     * 4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует
     * класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.
     * Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
     * • IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
     * • IsBoosted() - возвращает bool значение, есть ли у игрока перебор
     * • Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
     */

    class GenericPlayer : public Hand {
    protected:
        std::string m_Name;

    public:
        GenericPlayer(const std::string& name)
        : m_Name(name) {
        }

        virtual bool isHitting() const = 0;

        bool isBoosted() const {
            return getTotal() > TOTAL_SCORE;
        }

        void bust() const {
            if (!isBoosted())
                return;

            std::cout << m_Name << " is boosted!" << std::endl;
        }
    };

    /* ЗАДАНИЕ К УРОКУ 6 */
    /*
     * 3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
     * • virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
     * Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
     * • void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
     * • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
     * • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
     */

    class Player : public GenericPlayer {
    public:
        Player(const std::string& name) : GenericPlayer(name) {
        }

        virtual bool isHitting() const {
            std::cout << m_Name << ", do you want a hit? (Y/N): " << std::endl;
            char response;
            std::cin >> response;
            return (response == 'y' || response == 'Y');
        }

        void win() const {
            std::cout << m_Name << " wins!" << std::endl;
        }

        void lose() const {
            std::cout << m_Name << " loses..." << std::endl;
        }

        void push() const {
            std::cout << m_Name << " pushes." << std::endl;
        }
    };

    // ================ Тестирование ================

    void cardTest() {
        std::cout << "LESSON 3 TEST:" << std::endl;

        Card cardAce(Suit::Spades, CardValue::Ace);
        std::cout << cardAce.toString() << std::endl;

        cardAce.flip();
        std::cout << cardAce.toString() << std::endl;

        Card cardQueen(Suit::Diamonds, CardValue::Queen, true);
        std::cout << cardQueen.toString() << std::endl;
        cardQueen.flip();
        std::cout << cardQueen.toString() << std::endl;
    }

    void handTest() {
        std::cout << "LESSON 4 TEST:" << std::endl;

        Hand hand;

        Card* cardAce = new Card(Suit::Spades, CardValue::Ace);
        Card* cardQueen = new Card(Suit::Diamonds, CardValue::Queen);
        Card* cardTen = new Card(Suit::Clubs, CardValue::Ten);

        hand.add(cardAce);
        hand.add(cardQueen);
        hand.add(cardTen);
        std::cout << "Cards total sum = " << hand.getTotal() << std::endl;
        hand.clear();

        hand.add(cardAce);
        hand.add(cardQueen);
        std::cout << "Cards total sum = " << hand.getTotal() << std::endl;
        hand.clear();

        delete cardAce;
        delete cardTen;
        delete cardQueen;
    }

    void run() {
        std::cout << "====================== Blackjack test ======================" << std::endl;
        cardTest();
        handTest();
    }
}