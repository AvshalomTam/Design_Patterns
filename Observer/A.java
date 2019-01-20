import java.util.ArrayList;
import java.util.List;

class A implements Observable {
    private List<Observer> observersList;

    public A() {
        this.observersList = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer o) {
        this.observersList.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        this.observersList.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observersList) {
            observer.update(this, null);
        }
    }

    @Override
    public void notifyObservers(Object obj) {
        for (Observer observer : observersList) {
            observer.update(this, obj);
        }
    }
}