public class B implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        System.out.println("Received an update.");
    }
}