// Interface acting as abstraction
interface Car {
    startEngine(): void;
    shiftGear(gear: number): void;
    accelerate(): void;
    stop(): void;
    stopEngine(): void;
}

// Concrete class implementing the Car interface
class SportsCar implements Car {
    brand: string;
    model: string;
    isEngineOn: boolean;
    currentSpeed: number;
    currentGear: number;

    constructor(brand: string, model: string) {
        this.brand = brand;
        this.model = model;
        this.isEngineOn = false;
        this.currentSpeed = 0;
        this.currentGear = 0;
    }

    startEngine(): void {
        this.isEngineOn = true;
        console.log(`${this.brand} ${this.model}: Engine started.`);
    }

    shiftGear(gear: number): void {
        if (!this.isEngineOn) {
            console.log(`Cannot shift gear. Engine is off.`);
            return;
        }

        this.currentGear = gear;
        console.log(`${this.brand} ${this.model}: Shifted to gear ${this.currentGear}.`);
    }

    accelerate(): void {
        if (!this.isEngineOn || this.currentGear === 0) {
            console.log(`Cannot accelerate. Engine is off or gear is neutral.`);
            return;
        }

        this.currentSpeed += 10;
        console.log(`${this.brand} ${this.model}: Accelerating. Current speed: ${this.currentSpeed} km/h.`);
    }

    stop(): void {
        this.currentSpeed = 0;
        console.log(`${this.brand} ${this.model}: Car stopped.`);
    }

    stopEngine(): void {
        if (this.currentSpeed > 0) {
            console.log(`Stop the car before turning off the engine!`);
            return;
        }

        this.isEngineOn = false;
        this.currentGear = 0;
        console.log(`${this.brand} ${this.model}: Engine stopped.`);
    }
}


const car = new SportsCar('Ferrari', 'F8');

car.startEngine();
car.shiftGear(1);
car.accelerate();
car.shiftGear(2);
car.accelerate();
car.stop();
car.stopEngine();
