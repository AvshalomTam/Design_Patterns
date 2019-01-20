public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.safe();
        main.notSafe();
    }

    private void notSafe() {
        Thread a = new Thread(() -> {
            NotThreadSafeSingleton sA = NotThreadSafeSingleton.getInstance();
            for (int i = 0; i < 5; i++)
                sA.increase();
        }
        );
        Thread b = new Thread(() -> {
            NotThreadSafeSingleton sB = NotThreadSafeSingleton.getInstance();
            for (int i = 0; i < 4; i++)
                sB.decrease();
        }
        );

        a.start();
        b.start();

        try {
            Thread.sleep(50);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(NotThreadSafeSingleton.getInstance().getCounter());

    }

    public void safe() {
        Thread a = new Thread(() -> {
            ThreadSafeSingleton sA = ThreadSafeSingleton.getInstance();
            for (int i = 0; i < 5; i++)
                sA.increase();
        }
        );
        Thread b = new Thread(() -> {
            ThreadSafeSingleton sB = ThreadSafeSingleton.getInstance();
            for (int i = 0; i < 4; i++)
                sB.decrease();
        }
        );

        a.start();
        b.start();

        try {
            Thread.sleep(50);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(ThreadSafeSingleton.getInstance().getCounter());
    }

}
