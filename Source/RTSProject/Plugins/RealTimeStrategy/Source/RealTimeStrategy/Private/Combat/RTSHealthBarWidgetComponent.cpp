#include "Combat/RTSHealthBarWidgetComponent.h"

#include "GameFramework/Actor.h"

#include "Combat/RTSHealthComponent.h"


URTSHealthBarWidgetComponent::URTSHealthBarWidgetComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
    : Super(ObjectInitializer)
{
    // Set reasonable default values.
    Space = EWidgetSpace::Screen;
}

void URTSHealthBarWidgetComponent::BeginPlay()
{
    Super::BeginPlay();

    AActor* Owner = GetOwner();

    if (!IsValid(Owner))
    {
        return;
    }

    HealthComponent = Owner->FindComponentByClass<URTSHealthComponent>();

    if (!IsValid(HealthComponent))
    {
        return;
    }

    HealthComponent->OnHealthChanged.AddDynamic(this, &URTSHealthBarWidgetComponent::OnHealthChanged);
}

void URTSHealthBarWidgetComponent::OnHealthChanged(float OldHealth, float NewHealth, AActor* DamageCauser)
{
    UpdateHealthBar(HealthComponent->GetCurrentHealth() / HealthComponent->GetMaximumHealth());
}