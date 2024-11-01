package Factory;

import Container.Container;
import Enum.ContainerStrategy;

public interface Factory {
    Container createContainer(ContainerStrategy strategy);
}
