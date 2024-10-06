using System;

// Інтерфейс для реалізації (Implementor)
public interface IDevice
{
    bool IsEnabled();
    void Enable();
    void Disable();
    void SetVolume(int volume);
    int GetVolume();
}

// Конкретна реалізація (Concrete Implementor)
public class TV : IDevice
{
    private bool _isEnabled = false;
    private int _volume = 30;

    public bool IsEnabled() => _isEnabled;

    public void Enable() => _isEnabled = true;

    public void Disable() => _isEnabled = false;

    public void SetVolume(int volume) => _volume = volume;

    public int GetVolume() => _volume;
}

// Інтерфейс для абстракції (Abstraction)
public class Remote
{
    protected IDevice _device;

    public Remote(IDevice device)
    {
        _device = device;
    }

    public void TogglePower()
    {
        if (_device.IsEnabled())
            _device.Disable();
        else
            _device.Enable();
    }

    public void VolumeUp()
    {
        _device.SetVolume(_device.GetVolume() + 10);
    }

    public void VolumeDown()
    {
        _device.SetVolume(_device.GetVolume() - 10);
    }
}

// Покращена абстракція (Refined Abstraction)
public class AdvancedRemote : Remote
{
    public AdvancedRemote(IDevice device) : base(device) { }

    public void Mute()
    {
        _device.SetVolume(0);
    }
}

// Клієнтський код
class Program
{
    static void Main(string[] args)
    {
        IDevice tv = new TV();
        Remote remote = new AdvancedRemote(tv);

        Console.WriteLine("TV увімкнений? " + tv.IsEnabled());
        remote.TogglePower();
        Console.WriteLine("TV увімкнений? " + tv.IsEnabled());
        
        Console.WriteLine("Гучність: " + tv.GetVolume());
        remote.VolumeUp();
        Console.WriteLine("Гучність після збільшення: " + tv.GetVolume());
        
        remote.Mute();
        Console.WriteLine("Гучність після вимкнення звуку: " + tv.GetVolume());
    }
}
