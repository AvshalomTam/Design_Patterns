public class NotThreadSafeSingleton {
    private int counter;

    public int getCounter() {
        return this.counter;
    }

    private NotThreadSafeSingleton() {

    }

    private static NotThreadSafeSingleton instance;

    public static NotThreadSafeSingleton getInstance() {
        if (instance == null)
            instance = new NotThreadSafeSingleton();
        return instance;
    }

    public synchronized void increase() {
        this.counter = this.counter + 3;
    }

    public synchronized void decrease() {
        this.counter = this.counter - 2;
    }

}
