# Bridge Example

Цей репозиторій містить приклад патерну проектування "Міст".

## Патерн Міст (Bridge)

Патерн "Міст" дозволяє відокремити абстракцію від її реалізації, так що обидва можуть розвиватися незалежно.

### Приклад коду:

```csharp
// Інтерфейс Реалізації
public interface IDevice
{
    void PowerOn();
    void PowerOff();
    void SetVolume(int percent);
}

// Конкретна Реалізація
public class TV : IDevice
{
    public void PowerOn()
    {
        Console.WriteLine("Телевізор увімкнено.");
    }

    public void PowerOff()
    {
        Console.WriteLine("Телевізор вимкнено.");
    }

    public void SetVolume(int percent)
    {
        Console.WriteLine($"Гучність телевізора встановлена на {percent}%.");
    }
}

// Конкретна Реалізація
public class Radio : IDevice
{
    public void PowerOn()
    {
        Console.WriteLine("Радіо увімкнено.");
    }

    public void PowerOff()
    {
        Console.WriteLine("Радіо вимкнено.");
    }

    public void SetVolume(int percent)
    {
        Console.WriteLine($"Гучність радіо встановлена на {percent}%.");
    }
}

// Абстракція
public class RemoteControl
{
    protected IDevice _device;

    public RemoteControl(IDevice device)
    {
        _device = device;
    }

    public void PowerOn()
    {
        _device.PowerOn();
    }

    public void PowerOff()
    {
        _device.PowerOff();
    }

    public void SetVolume(int percent)
    {
        _device.SetVolume(percent);
    }
}

// Розширена Абстракція
public class AdvancedRemoteControl : RemoteControl
{
    public AdvancedRemoteControl(IDevice device) : base(device) { }

    public void Mute()
    {
        _device.SetVolume(0);
        Console.WriteLine("Гучність встановлена на нуль.");
    }
}
