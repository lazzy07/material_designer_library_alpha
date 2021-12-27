import DeviceInfo from "./DeviceInfo";

export interface MatdV8 {
  new (): MatdV8;
  setComputationDevice: (platform: number, device: number) => void;
  getAvailableEngines: () => string[];
  setEngine: (engineID: number) => void;
  getAvailableDevices: () => DeviceInfo[];
}
