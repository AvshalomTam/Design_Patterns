public class ThreadSafeSingleton {
    private int counter;

    public int getCounter() {
        return this.counter;
    }

    private ThreadSafeSingleton() {

    }

    private static class Helper {
        private static ThreadSafeSingleton instance = new ThreadSafeSingleton();
    }

    public static ThreadSafeSingleton getInstance() {
        return Helper.instance;
    }

    public synchronized void increase() {
        this.counter = this.counter + 3;
    }

    public synchronized void decrease() {
        this.counter = this.counter - 2;
    }
}