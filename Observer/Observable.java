public interface Observable {
    void addObserver(Observer o);

    void removeObserver(Observer o);

    void notifyObservers();

    void notifyObservers(Object obj);
}