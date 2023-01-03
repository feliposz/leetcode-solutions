public class Foo {
    private System.Threading.Semaphore a, b;

    public Foo() {
        a = new System.Threading.Semaphore(0, 1);
        b = new System.Threading.Semaphore(0, 1);
    }

    public void First(Action printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        a.Release();
    }

    public void Second(Action printSecond) {
        a.WaitOne();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        b.Release();
    }

    public void Third(Action printThird) {
        b.WaitOne();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}