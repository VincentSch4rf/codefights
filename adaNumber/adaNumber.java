boolean adaNumber(String line) {
if(line.isEmpty())
        return false;
    line = line.replaceAll("_", "");
    if(line.isEmpty())
        return false;
    if (line.replaceAll("\\d*", "").isEmpty())
        return true;
    if (line.contains("#")) {
        if (!line.endsWith("#"))
            return false;
        if ((line.length() - line.replace("#", "").length()) > 2)
            return false;
        String[] parts = line.split("#");
        if(parts.length != 2) {
            return false;
        }
        if (parts[0].isEmpty()) {
            return false;
        }
        int base;
        try {
            base = Integer.parseInt(parts[0]);
        } catch (Exception e) {
            return false;
        }
        if (parts[0].length() > 2 || Integer.parseInt(parts[0]) < 2 || Integer.parseInt(parts[0]) > 16) {
            return false;
        }
        for (char c : parts[1].toCharArray()) {
            if (c >= 97) {
                if (c - 87 >= base) {
                    return false;
                }
            } else if (c >= 65) {
                if (c - 55 >= base) {
                    return false;
                }
            } else if (c >= 48) {
                if (c - 48 >= base) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
