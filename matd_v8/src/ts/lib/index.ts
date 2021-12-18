import { MatdV8 as MatdInf } from "../interfaces/MatdV8";

const {
  MatdV8,
}: {
  MatdV8: MatdInf;
} = require("../../../../bin/Windows/x64/Debug/matd_v8_bindings.node") as any;

export default { class: MatdV8 };
